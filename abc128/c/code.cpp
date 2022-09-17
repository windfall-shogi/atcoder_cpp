#include <iostream>
#include <vector>

// 縦がM、横がN
int table[11][11];

int main()
{
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int k;
        std::cin >> k;
        for (int j = 0; j < k; ++j)
        {
            int s;
            std::cin >> s;
            table[i][s - 1] = 1;
        }
    }
    std::vector<int> ps(m);
    for (int i = 0; i < m; ++i)
    {
        std::cin >> ps[i];
    }

    int ans = 0;
    for (int x = 0; x < (1 << n); ++x)
    {
        bool ok = true;
        for (int i = 0; i < m; ++i)
        {
            int on_count = 0;
            for (int j = 0; j < n; ++j)
            {
                if (((x >> j) & 0x1) == 1 && table[i][j] == 1)
                {
                    ++on_count;
                }
            }
            if (on_count % 2 != ps[i])
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            ++ans;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}
