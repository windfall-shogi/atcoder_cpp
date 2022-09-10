#include <iostream>

int64_t solve(const int64_t x)
{
    if (x == 0)
    {
        return 0;
    }

    if (x % 2 == 0)
    {
        const int64_t k = x - 2;
        const int64_t n = k / 2 + 1;
        return x ^ (n & 0x1);
    }
    else
    {
        const int64_t k = x;
        const int64_t n = k / 2 + 1;
        return n & 0x1;
    }
}

int main()
{
    int64_t a, b;
    std::cin >> a >> b;

    if (a == 0)
    {
        std::cout << solve(b) << std::endl;
    }
    else
    {
        std::cout << (solve(a - 1) ^ solve(b)) << std::endl;
    }
    return 0;
}
