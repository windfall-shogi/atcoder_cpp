#include <iostream>

constexpr int MAX = 2010;
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

int main()
{
    COMinit();

    int n, k;
    std::cin >> n >> k;
    const int m = n - k;

    for (int i = 1; i <= k; ++i)
    {
        const int64_t a = COM(k - 1, i - 1);
        const int64_t b = COM(m + 1, i);

        std::cout << (a * b) % MOD << std::endl;
    }
    return 0;
}
