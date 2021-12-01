#include <iostream>
#include <vector>

int main()
{
    int N;
    std::cin >> N;
    std::vector<int64_t> As(N + 1), Bs(N + 1);
    for (int i = 1; i <= N; ++i)
    {
        std::cin >> As[i];
    }
    for (int i = 1; i <= N; ++i)
    {
        std::cin >> Bs[i];
    }

    constexpr int64_t INF = 1LL << 60;
    using V = std::vector<int64_t>;
    using W = std::vector<V>;
    // 各ノードを0,1の二色で塗り分ける
    // ノード0の色を0に固定しても一般性を失わない
    // dp[i][j][k]: ノードiまで決定した時のコスト
    //              ただし、ノードiの色はjで、ノード1の色はk
    std::vector<W> dp(N + 1, W(2, V(2, INF)));
    dp[1][0][0] = As[1];
    dp[1][1][1] = 0;
    for (int i = 2; i <= N; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            for (int k = 0; k < 2; ++k)
            {
                for (int l = 0; l < 2; ++l)
                {
                    const auto tmp = dp[i - 1][l][k] + (j == 0 ? As[i] : 0) + (j == l ? Bs[i - 1] : 0);
                    dp[i][j][k] = std::min(dp[i][j][k], tmp);
                }
            }
        }
    }
    int64_t ans = INF;
    for (int j = 0; j < 2; ++j)
    {
        for (int k = 0; k < 2; ++k)
        {
            ans = std::min(ans, dp[N][j][k] + (j == k ? Bs[N] : 0));
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
