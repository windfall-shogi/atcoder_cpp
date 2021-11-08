#include <iostream>
#include <unordered_map>

constexpr int32_t MOD = 1000000007;
constexpr int MAX = 110000;
int64_t fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit()
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
int64_t COM(int n, int k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

using Map = std::unordered_map<int64_t, int64_t>;

Map factorize(const int64_t m)
{
    Map map;

    int64_t c = 0;
    int64_t x = m;
    while (x % 2 == 0)
    {
        ++c;
        x /= 2;
    }
    if (c != 0)
    {
        map.emplace(2, c);
    }

    int64_t k = 3;
    while (x != 1)
    {
        c = 0;
        while (x % k == 0)
        {
            ++c;
            x /= k;
        }
        if (c != 0)
        {
            map.emplace(k, c);
        }

        k += 2;
    }

    return map;
}

int main()
{
    int n, m;
    std::cin >> n >> m;

    COMinit();

    Map map = factorize(m);
    int64_t ans = 1;
    for (const auto &e : map)
    {
        const int64_t tmp = COM(e.second + n - 1, n - 1);
        ans *= tmp;
        ans %= MOD;
    }

    std::cout << ans << std::endl;

    return 0;
}
