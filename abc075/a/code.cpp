#include <iostream>

int main()
{
    int a, b, c;
    std::cin >> a >> b >> c;
    if (a == b)
    {
        std::cout << c << std::endl;
    }
    else if (a == c)
    {
        std::cout << b << std::endl;
    }
    else
    {
        std::cout << a << std::endl;
    }

    return 0;
}
