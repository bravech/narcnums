#include "NumberGen.h"
#include <iostream>
#define MAX_R 25 // Maximum length of number

std::optional<std::vector<char>> NumberGen::nextNumber()
{
    int i = nums.size() - 1;
    bool end = false;
    while (i >= 0)
    {
        if (nums.at(i) != 9)
        {
            end = true;
            break;
        }
        i--;
    }
    if (!end)
        return {};
    int start = nums[i];
    for (; i < (int)nums.size(); i++)
    {
        nums[i] = start + 1;
    }
    return nums;
    // mpz_class num(0);
    // for (size_t i = 0; i < nums.size(); i++)
    // {
    //     mpz_class b;
    //     mpz_ui_pow_ui(b.get_mpz_t(), 10, i);
    //     num += nums[i] * b;
    // }
    // return num;
}

NumberGen::NumberGen(int r)
{
    nums = std::vector<char>(r, 0);
    for (int i = 0; i < MAX_R; i++)
    {
        mpz_class n;
        mpz_ui_pow_ui(n.get_mpz_t(), 10, i);
        powTable[i] = n;
    }
}