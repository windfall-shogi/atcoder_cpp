#include <iostream>

int main()
{
    int a, b, x;
    std::cin >> a >> b >> x;
    std::cout << ((x >= a && x <= a + b) ? "YES" : "NO") << std::endl;
    return 0;
}
