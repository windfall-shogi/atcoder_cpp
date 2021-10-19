#include <iostream>

int main()
{
    int a, b;
    std::cin >> a >> b;
    const int delta = b - a;
    const int total = (1 + delta - 1) * (delta - 1) / 2;
    std::cout << total - a << std::endl;
    return 0;
}
