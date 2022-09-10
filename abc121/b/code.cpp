#include <iostream>
#include <vector>

int main()
{
    int n, m, c;
    std::cin >> n >> m >> c;
    std::vector<int> bs(m);
    for (int i = 0; i < m; ++i)
    {
        std::cin >> bs[i];
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int score = c;
        for (int j = 0; j < m; ++j)
        {
            int a;
            std::cin >> a;
            score += a * bs[j];
        }
        if (score > 0)
        {
            ++ans;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}
