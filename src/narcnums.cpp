#include <iostream>
#include <vector>
#include <gmpxx.h>
#include "util.h"
#include "NumberGen.h"



int main()
{
    NumberGen numGen(5);
    auto a = numGen.nextNumber();
    while (a.has_value()) {
        std::cout << *a << std::endl;
        a = numGen.nextNumber();
    }
}
