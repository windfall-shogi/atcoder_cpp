#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

constexpr int64_t MOD = 998244353;
constexpr int64_t MAX = 5010;
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

int64_t count[26];
int64_t cum[26];

int64_t solve(const int64_t size, const int64_t index)
{
    if (index == 26 || size == 0)
    {
        return 1;
    }

    int64_t ans = 0;
    for (int64_t i = std::max<int64_t>(0, size - cum[index]); i <= std::min(count[index], size); ++i)
    {
        int64_t tmp = COM(size, i);
        tmp *= solve(size - i, index + 1);
        tmp %= MOD;

        ans += tmp;
        ans %= MOD;
    }
    return ans;
}

int main()
{
    COMinit();

    std::string S;
    std::cin >> S;
    for (const char c : S)
    {
        ++count[c - 'a'];
    }
    cum[25] = 0;
    for (int i = 24; i >= 0; --i)
    {
        cum[i] = cum[i + 1] + count[i + 1];
    }

    int64_t ans = 0;
    for (int64_t i = 1; i <= S.size(); ++i)
    {
        ans += solve(i, 0);
        ans %= MOD;
    }

    std::cout << ans << std::endl;
    return 0;
}
