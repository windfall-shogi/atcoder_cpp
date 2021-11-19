#include <iostream>
#include <vector>

int main()
{
    int64_t n, k;
    std::cin >> n >> k;
    std::vector<int64_t> as(n);
    for (int64_t i = 0; i < n; ++i)
    {
        std::cin >> as[i];
    }

    constexpr int max_d = 40;
    std::vector<int64_t> counter(max_d);
    for (const auto a : as)
    {
        for (int i = 0; i < max_d; ++i)
        {
            if (a & (1LL << i))
            {
                ++counter[i];
            }
        }
    }

    int64_t dp[max_d + 1][2];
    for (int i = 0; i <= max_d; ++i)
    {
        dp[i][0] = dp[i][1] = -(1LL << 50);
    }

    dp[max_d][0] = 0;
    for (int i = max_d - 1; i >= 0; --i)
    {
        const int64_t mask = 1LL << i;
        if (k & mask)
        {
            // kのbitが1なので、xのbitも1にする
            dp[i][0] = dp[i + 1][0] + mask * (n - counter[i]);
            // kよりxは小さい
            dp[i][1] = dp[i + 1][0] + mask * counter[i];
        }
        else
        {
            // kのbitが0なので、xのbitも0にする
            dp[i][0] = dp[i + 1][0] + mask * counter[i];
        }
        if (dp[i + 1][1] >= 0)
        {
            dp[i][1] = std::max(dp[i][1],
                                dp[i + 1][1] + mask * std::max(n - counter[i], counter[i]));
        }
    }

    std::cout << std::max(dp[0][0], dp[0][1]) << std::endl;

    return 0;
}
