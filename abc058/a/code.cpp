#include <iostream>

int main()
{
    int a, b, c;
    std::cin >> a >> b >> c;
    if (b - a == c - b)
    {
        std::cout << "YES";
    }
    else
    {
        std::cout << "NO";
    }
    std::cout << std::endl;
    return 0;
}
