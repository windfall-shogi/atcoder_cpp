#include <iostream>

int64_t f(const int64_t x)
{
    return x * x + 2 * x + 3;
}

int main()
{
    int64_t t;
    std::cin >> t;
    std::cout << f(f(f(t) + t) + f(f(t))) << std::endl;
    return 0;
}
