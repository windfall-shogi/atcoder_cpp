#include <iostream>

constexpr int32_t MOD = 1000000007;

int main()
{
    int n;
    std::cin >> n;
    int64_t p = 1;
    for (int i = 0; i < n; ++i)
    {
        p *= (i + 1);
        p %= MOD;
    }

    std::cout << p << std::endl;

    return 0;
}
