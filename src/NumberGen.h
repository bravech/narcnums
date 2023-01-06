#include <stdio.h>
#include <gmpxx.h>
#include <vector>
#include <optional>

#ifndef NumberGen_hpp
#define NumberGen_hpp
// template<size_t rows, size_t cols>
class NumberGen
{
public:
    std::optional<std::vector<char>> nextNumber();
    NumberGen(const NumberGen &) = delete;
    NumberGen() = delete;
    NumberGen(int r);

private:
    // Vector repr of base 10 number
    std::vector<char> nums;
    mpz_class powTable[30];
};

#endif /* NumberGen_h */