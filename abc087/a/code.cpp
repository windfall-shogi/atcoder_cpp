#include <iostream>

int main()
{
    int x, a, b;
    std::cin >> x >> a >> b;
    x -= a;
    std::cout << x % b << std::endl;
    return 0;
}
