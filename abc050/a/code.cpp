#include <iostream>

int main()
{
    int a, b;
    char op;
    std::cin >> a >> op >> b;
    if (op == '+')
    {
        std::cout << a + b;
    }
    else
    {
        std::cout << a - b;
    }
    std::cout << std::endl;

    return 0;
}
