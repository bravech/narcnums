#include <gmpxx.h>
#include <cassert>
#include <array>

using DigitCounts = std::array<char, 10>;

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

// Returns if two numbers have same count of digits
bool sameDigitCounts(mpz_class const &a, std::vector<char> b)
{
    int aCounts[10] = {0};
    int bCounts[10] = {0};
    // while (a > 0)
    // {
    //     mpz_class bigDig = a % 10;
    //     short dig = bigDig.get_ui();
    //     aCounts[dig]++;
    //     a = a / 10;
    // }
    std::string s = a.get_str();

    for (size_t i = 0; i < b.size(); i++)
    {
        assert(b[i] < 10 && b[i] >= 0);
        bCounts[b[i]]++;
    }

    for (int i = 0; i < 10; i++)
    {
        if (aCounts[i] != bCounts[i])
            return false;
    }
    return true;
}

DigitCounts getDigitCounts(std::vector<char> const &num)
{
    DigitCounts out = {0};
    for (char const &dig : num)
    {
        out[dig]++;
    }
    return out;
}

DigitCounts getDigitCounts(mpz_class a)
{
    DigitCounts out{};
    auto aStr = a.get_str();
    for (char c : aStr)
    {
        out[c - '0']++;
    }
    return out;
}

template <typename T>
void printVec(std::vector<T> q)
{
    std::cout << "(";
    for (auto c : q)
    {
        std::cout << (short)c << ",";
    }
    std::cout << ")" << std::endl;
}

template <typename T>
void printVec(std::array<T, 10> q)
{
    std::cout << "(";
    for (auto c : q)
    {
        std::cout << (short)c << ",";
    }
    std::cout << ")" << std::endl;
}