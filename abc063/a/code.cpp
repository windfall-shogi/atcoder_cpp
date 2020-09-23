#include <iostream>

int main()
{
    int a, b;
    std::cin >> a >> b;
    const auto c = a + b;
    if (c >= 10)
    {
        std::cout << "error" << std::endl;
    }
    else
    {
        std::cout << c << std::endl;
    }
    return 0;
}
