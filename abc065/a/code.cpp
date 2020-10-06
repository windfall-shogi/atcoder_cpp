#include <iostream>

int main()
{
    int x, a, b;
    std::cin >> x >> a >> b;

    if (a >= b)
    {
        std::cout << "delicious";
    }
    else if (b - a <= x)
    {
        std::cout << "safe";
    }
    else
    {
        std::cout << "dangerous";
    }
    std::cout << std::endl;

    return 0;
}
