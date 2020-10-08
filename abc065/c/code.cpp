#include <iostream>

constexpr int32_t MOD = 1000000007;

int main()
{
    int n, m;
    std::cin >> n >> m;

    if (abs(n - m) > 1)
    {
        std::cout << 0 << std::endl;
        return 0;
    }

    int64_t total = 1;
    for (int i = 0; i < n; ++i)
    {
        total *= i + 1;
        total %= MOD;
    }
    for (int i = 0; i < m; ++i)
    {
        total *= i + 1;
        total %= MOD;
    }
    if (m == n)
    {
        total *= 2;
        total %= MOD;
    }

    std::cout << total << std::endl;
    return 0;
}
