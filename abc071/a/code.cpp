#include <iostream>

int main()
{
    int x, a, b;
    std::cin >> x >> a >> b;
    if (std::abs(x - a) < std::abs(x - b))
    {
        std::cout << 'A' << std::endl;
    }
    else
    {
        std::cout << 'B' << std::endl;
    }
    return 0;
}
