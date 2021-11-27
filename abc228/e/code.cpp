#include <iostream>

int64_t power(const int64_t x, const int64_t y, const int64_t p)
{
    int64_t ans = 1;
    int64_t v = x % p;
    int64_t k = y;
    while (k)
    {
        if (k & 1LL)
        {
            ans *= v;
            ans %= p;
        }
        v *= v;
        v %= p;

        k >>= 1LL;
    }
    return ans;
}

int main()
{
    constexpr int64_t p = 998244353;
    int64_t n, k, m;
    std::cin >> n >> k >> m;
    // ans=M^(K^N) mod p
    // フェルマーの小定理が必要
    // ちなみに998244353は素数

    if (m % p == 0)
    {
        std::cout << 0 << std::endl;
        return 0;
    }

    const int64_t tmp_ans = power(k, n, p - 1);
    const int64_t ans = power(m, tmp_ans, p);
    std::cout << ans << std::endl;

    return 0;
}
