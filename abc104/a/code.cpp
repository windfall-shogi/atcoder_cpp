#include <iostream>

int main()
{
    int r;
    std::cin >> r;
    if (r < 1200)
    {
        std::cout << "ABC";
    }
    else if (r < 2800)
    {
        std::cout << "ARC";
    }
    else
    {
        std::cout << "AGC";
    }
    std::cout << std::endl;
    return 0;
}
