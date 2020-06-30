#include <iostream>

int main()
{
    int x;
    std::cin >> x;
    if (x < 1200)
    {
        std::cout << "ABC";
    }
    else
    {
        std::cout << "ARC";
    }
    std::cout << std::endl;
    return 0;
}
