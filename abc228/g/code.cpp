#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
    // 参考: https://kmjp.hatenablog.jp/entry/2021/11/22/0900
    constexpr int64_t mod = 998244353;

    int H, W, N;
    std::cin >> H >> W >> N;
    int grid[10][10];
    for (int i = 0; i < H; ++i)
    {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < W; ++j)
        {
            grid[i][j] = s[j] - '0';
        }
    }

    constexpr int size = 1 << 10;
    std::vector<int> fa[size], fb[size];
    for (int mask = 1; mask < size; ++mask)
    {
        for (int c = 1; c <= 9; ++c)
        {
            int to = 0;
            for (int i = 0; i < H; ++i)
            {
                if (mask & (1 << i))
                {
                    for (int j = 0; j < W; ++j)
                    {
                        if (grid[i][j] == c)
                        {
                            to |= 1 << j;
                        }
                    }
                }
            }
            fa[mask].emplace_back(to);

            to = 0;
            for (int j = 0; j < W; ++j)
            {
                if (mask & (1 << j))
                {
                    for (int i = 0; i < H; ++i)
                    {
                        if (grid[i][j] == c)
                        {
                            to |= 1 << i;
                        }
                    }
                }
            }
            fb[mask].emplace_back(to);
        }
    }

    std::vector<int64_t> A(size), B(size), C(size);
    A[(1 << H) - 1] = 1;
    for (int i = 0; i < N; ++i)
    {
        std::fill(B.begin(), B.end(), 0);
        std::fill(C.begin(), C.end(), 0);
        for (int mask = 1; mask < size; ++mask)
        {
            for (const auto t : fa[mask])
            {
                B[t] += A[mask];
                B[t] %= mod;
            }
        }
        for (int mask = 1; mask < size; ++mask)
        {
            for (const auto t : fb[mask])
            {
                C[t] += B[mask];
                C[t] %= mod;
            }
        }
        A.swap(C);
    }

    int64_t ans = 0;
    for (int mask = 1; mask < size; ++mask)
    {
        ans += A[mask];
    }

    std::cout << ans % mod << std::endl;

    return 0;
}
