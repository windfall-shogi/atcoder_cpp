#include <iostream>
#include <vector>

constexpr int64_t MOD = 1000000007;

int64_t dp[2010][2010];

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<int> s(n + 1), t(m + 1);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> s[i + 1];
    }
    for (int j = 0; j < m; ++j)
    {
        std::cin >> t[j + 1];
    }
    for (int i = 0; i <= n; ++i)
    {
        dp[i][0] = 1;
    }
    for (int j = 0; j <= m; ++j)
    {
        dp[0][j] = 1;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (s[i] == t[j])
            {
                dp[i][j] += dp[i - 1][j - 1];
                dp[i][j] %= MOD;
            }
            dp[i][j] += dp[i - 1][j];
            dp[i][j] %= MOD;
            dp[i][j] += dp[i][j - 1];
            dp[i][j] %= MOD;
            dp[i][j] -= dp[i - 1][j - 1];
            if (dp[i][j] < 0)
            {
                dp[i][j] += MOD;
            }
            else if (dp[i][j] >= MOD)
            {
                dp[i][j] -= MOD;
            }
        }
    }
    std::cout << dp[n][m] << std::endl;

    return 0;
}
