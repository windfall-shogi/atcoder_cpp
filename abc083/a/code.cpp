#include <iostream>

int main()
{
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    if (a + b > c + d)
    {
        std::cout << "Left";
    }
    else if (a + b == c + d)
    {
        std::cout << "Balanced";
    }
    else
    {
        std::cout << "Right";
    }
    std::cout << std::endl;

    return 0;
}
