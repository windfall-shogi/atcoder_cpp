#include <iostream>

int main()
{
    int a, b;
    std::cin >> a >> b;
    std::cout << (b % a == 0 ? a + b : b - a) << std::endl;
    return 0;
}
