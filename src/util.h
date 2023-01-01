#include <gmpxx.h>

// Returns if two numbers have same count of digits
bool sameDigitCounts(mpz_class a, mpz_class b)
{
    int aCounts[10] = {0};
    int bCounts[10] = {0};
    mpz_class ten(10);
    while (a > 0)
    {
        mpz_class bigDig = a % ten;
        short dig = bigDig.get_ui();
        aCounts[dig]++;
        a = a / 10;
    }
    while (b > 0)
    {
        mpz_class bigDig = b % ten;
        short dig = bigDig.get_ui();
        bCounts[dig]++;
        b = b / 10;
    }
    for (int i = 0; i < 10; i++)
    {
        if (aCounts[i] != bCounts[i])
            return false;
    }
    return true;
}

void printVec(std::vector<int> q)
{
    std::cout << "(";
    for (auto c : q)
    {
        std::cout << c << ",";
    }
    std::cout << ")"  << std::endl;
}