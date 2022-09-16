#include <iostream>
#include <vector>

constexpr int MAX = 200000 + 10;
constexpr int MOD = 1000000007;

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

int64_t solve(const int64_t n, const int64_t m, const int64_t k)
{
    int64_t ans = 0;
    for (int64_t i = 1; i <= n; ++i)
    {
        const int64_t pattern = (n - i) * m * m % MOD;
        ans += (i * pattern) % MOD;
        ans %= MOD;
    }
    return ans;
}

int main()
{
    int64_t n, m, k;
    std::cin >> n >> m >> k;

    COMinit();

    int64_t ans = solve(n, m, k) + solve(m, n, k);
    ans %= MOD;
    ans *= COM(n * m - 2, k - 2);
    ans %= MOD;
    std::cout << ans << std::endl;

    return 0;
}
