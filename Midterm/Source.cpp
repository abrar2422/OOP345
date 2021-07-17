#include<iostream>
#include <string>
#include "Header.h"

int main()
{
    int iarr1[]{ 2, 3, 5 };
    int val1 = 2;

    double darr1[]{ 4.44, 4.44, 4.44 };
    double val2 = 4.44;

    std::string sarr1[]{ "Banana", "Apple", "Coffee", "Pine", "Orange" };
    std::string val3 = "Wine";

    if (!allof(iarr1, 3, val1))
        std::cout << "First case not all match" << std::endl;

    if (allof(darr1, 3, val2))
        std::cout << "Second case all match" << std::endl;

    if (!allof(sarr1, 5, val3))
        std::cout << "Third case not all match" << std::endl;
}