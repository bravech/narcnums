#include <iostream>
#include <vector>
#include <gmpxx.h>
#include <omp.h>
#include "util.h"
#include "NumberGen.h"

#define PARTITION_SIZE 10000000

mpz_class powTable[50][50];

int main()
{
    for (int i = 0; i < 50; i++)
    {
        // mpz_class n = 1;
        for (int j = 0; j < 50; j++)
        {
            mpz_class n;
            mpz_ui_pow_ui(n.get_mpz_t(), i, j);
            // n = n * i;
            powTable[i][j] = n;
        }
    }
    std::vector<std::vector<char>> groups;
    std::cout << "done" << std::endl;
    groups.reserve(PARTITION_SIZE);
#pragma omp parallel for
    for (int r = 1; r < 40; r++)
    {
        std::cout << "r: " << r << std::endl;
        NumberGen numGen(r);
        bool running = true;
        while (running)
        {
            auto a = numGen.nextNumber();
            groups.clear();
            while (a.has_value() && groups.size() < PARTITION_SIZE)
            {
                groups.push_back(*a);
                a = numGen.nextNumber();
            }
            // if (!a.has_value()) running = false;
            running = a.has_value();

            #pragma omp parallel for
            for (size_t i = 0; i < groups.size(); i++)
            {
                auto &a = groups[i];
                mpz_class n = 0;
                for (size_t i = 0; i < a.size(); i++)
                {
                    n += powTable[a.at(i)][a.size()];
                }

                if (sameDigitCounts(n, a))
                {
                    std::cout << n << std::endl;
                }
            }
        }
    }
}
