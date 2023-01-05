#include <iostream>
#include <vector>
#include <gmpxx.h>
#include "util.h"
#include "NumberGen.h"

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

   for (int r = 21; r < 22; r++)
    {
        std::cout << "r: " << r << std::endl;
        NumberGen numGen(r);
        auto a = numGen.nextNumber();
        while (a.has_value())
        {
            mpz_class n = 0;
            for (size_t i = 0; i < a->size(); i++)
            {
                n += powTable[a->at(i)][a->size()];
            }

            if (sameDigitCounts(n, *a))
            {
                std::cout << n << std::endl;
            }

            a = numGen.nextNumber();
        }
    }
}
