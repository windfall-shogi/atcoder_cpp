#include <iostream>

int main()
{
    char a, b;
    std::cin >> a >> b;
    if (a == b)
    {
        std::cout << 'H';
    }
    else
    {
        std::cout << 'D';
    }
    std::cout << std::endl;
    return 0;
}
