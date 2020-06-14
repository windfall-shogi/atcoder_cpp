#include <iostream>

int main()
{
    int64_t a, b, x;
    std::cin >> a >> b >> x;
    a = (a + x - 1) / x * x;
    b = b / x * x;
    const int64_t n = (b - a) / x + 1;
    std::cout << n << std::endl;
    return 0;
}
