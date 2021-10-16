#include <iostream>

int main()
{
    int a, b;
    std::cin >> a >> b;
    std::cout << a - (a <= b ? 0 : 1) << std::endl;
    return 0;
}
