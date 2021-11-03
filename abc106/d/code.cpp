#include <iostream>
#include <vector>

int TABLE[501][501];

int main()
{
    int n, m, q;
    std::cin >> n >> m >> q;
    for (int i = 0; i < m; ++i)
    {
        int l, r;
        std::cin >> l >> r;
        ++TABLE[l][r];
    }

    for (int i = 0; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            TABLE[i][j] += TABLE[i][j - 1];
        }
    }
    for (int j = 0; j <= n; ++j)
    {
        for (int i = 1; i <= n; ++i)
        {
            TABLE[i][j] += TABLE[i - 1][j];
        }
    }

    std::vector<int> ans(q);
    for (int i = 0; i < q; ++i)
    {
        int s, t;
        std::cin >> s >> t;
        ans[i] = TABLE[t][t] - TABLE[t][s - 1] - TABLE[s - 1][t] + TABLE[s - 1][s - 1];
    }

    for (int i = 0; i < q; ++i)
    {
        std::cout << ans[i] << std::endl;
    }

    return 0;
}
