#include <iostream>

int main()
{
    char x, y;
    std::cin >> x >> y;
    if (x == y)
    {
        std::cout << '=' << std::endl;
    }
    else if (x < y)
    {
        std::cout << '<' << std::endl;
    }
    else
    {
        std::cout << '>' << std::endl;
    }
    return 0;
}
