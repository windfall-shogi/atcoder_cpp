#include <iostream>
#include <vector>
#include <cstdint>

// https://drken1215.hatenablog.com/entry/2018/06/08/210000
constexpr int MAX = 310000;
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

    int h, w, a, b;
    std::cin >> h >> w >> a >> b;

    // 全体
    const int64_t total = COM(h - 1 + w - 1, h - 1);
    // 進入禁止エリアを通るパターン
    int64_t n = 0;
    // 進入禁止エリアの一つ手前までに下に降りる回数
    const int v = h - a - 1;
    for (int i = 0; i < b; ++i)
    {
        const int64_t tmp0 = COM(v + i, v);
        const int64_t tmp1 = COM(a - 1 + w - 1 - i, a - 1);

        n += tmp0 * tmp1 % MOD;
        n %= MOD;
    }
    int result = (total - n) % MOD;
    if (result < 0)
    {
        result += MOD;
    }

    std::cout << result << std::endl;

    return 0;
}
