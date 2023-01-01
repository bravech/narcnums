#include "NumberGen.h"
#define MAX_R 25 // Maximum length of number

std::optional<mpz_class> NumberGen::nextNumber()
{
    size_t i = nums.size();
    bool end = false;
    while (i >= 0)
    {
        if (nums[i] != 9)
        {
            end = true;
            break;
        }
        i--;
    }
    if (!end) return {};
    int start = nums[i];
    for (; i < nums.size(); i++)
    {
        nums[i] = start + 1;
    }
    mpz_class num(0);
    for (size_t i = 0; i < nums.size(); i++)
    {
        mpz_class b;
        mpz_ui_pow_ui(b.get_mpz_t(), 10, i);
        num += nums[i] * b;
    }
    return num;
}

NumberGen::NumberGen(int r)
{
    nums = std::vector<char>(r, MAX_R);
    for (int i = 0; i < MAX_R; i++)
    {
        mpz_class n;
        mpz_ui_pow_ui(n.get_mpz_t(), 10, i);
        powTable[i] = n;
    }
}