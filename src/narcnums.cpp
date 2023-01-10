#include <iostream>
#include <vector>
#include <gmpxx.h>
#include <omp.h>
#include "util.h"
#include "NumberGen.h"

#define PARTITION_SIZE 10000000

mpz_class powTable[50][50];

mpz_class NarcOp(DigitCounts const &a, int r)
{
    mpz_class n = 0;
    for (size_t i = 0; i < a.size(); i++)
    {
        n += powTable[i][r] * a[i];
    }
    return n;
}

int main()
{
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            mpz_class n;
            mpz_ui_pow_ui(n.get_mpz_t(), i, j);
            powTable[i][j] = n;
        }
    }
    std::vector<std::array<char, 10>> groups;
    groups.reserve(PARTITION_SIZE);
    for (int r = 1; r < 20; r++)
    {
        NumberGen numGen(r);
        bool running = true;
        while (running)
        {
            auto a = numGen.nextNumber();
            groups.clear();
            while (a.has_value() && groups.size() < PARTITION_SIZE)
            {
                groups.emplace_back(getDigitCounts(*a));
                a = numGen.nextNumber();
            }
            running = a.has_value();

            #pragma omp parallel for
            for (size_t i = 0; i < groups.size(); i++)
            {
                auto & a = groups[i];

                auto n = NarcOp(a, r);
                auto nCount = getDigitCounts(n);

                if (nCount == a)
                {
                    std::cout << r << " " << n << std::endl;
                }
            }
        }
    }
}
