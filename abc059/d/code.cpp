#include <iostream>

int main()
{
    int64_t x, y;
    std::cin >> x >> y;
    if (x + y <= 1)
    {
        std::cout << "Brown";
    }
    else if (abs(x - y) > 1)
    {
        std::cout << "Alice";
    }
    else
    {
        std::cout << "Brown";
    }
    std::cout << std::endl;
    return 0;
}
