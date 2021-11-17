#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>

constexpr int64_t INF = static_cast<int64_t>(1) << 40;
int main()
{
    int n, k;
    std::cin >> n >> k;
    std::vector<std::vector<int64_t>> sushis(n);
    for (int i = 0; i < n; ++i)
    {
        int t, d;
        std::cin >> t >> d;
        --t;
        sushis[t].emplace_back(d);
    }

    for (auto &e : sushis)
    {
        if (e.empty())
        {
            e.emplace_back(-INF);
        }
        else
        {
            std::sort(e.begin(), e.end(), std::greater<int64_t>());
        }
    }
    std::sort(sushis.begin(), sushis.end(), [](const std::vector<int64_t> &lhs, const std::vector<int64_t> &rhs)
              { return lhs[0] > rhs[0]; });

    int64_t current = 0;
    std::priority_queue<int64_t> queue;
    for (int i = 0; i < k; ++i)
    {
        current += sushis[i][0];
        for (int j = 1; j < sushis[i].size(); ++j)
        {
            queue.push(sushis[i][j]);
        }
    }
    for (int i = k; i < n; ++i)
    {
        for (const auto v : sushis[i])
        {
            queue.push(v);
        }
    }

    int64_t ans = current + static_cast<int64_t>(k) * k;
    for (int i = k - 1; i >= 1; --i)
    {
        const auto v = sushis[i][0];
        const auto w = queue.top();
        if (w > v)
        {
            queue.pop();
            queue.push(v);

            current += w;
            current -= v;
        }
        ans = std::max(ans, current + static_cast<int64_t>(i) * i);
    }

    std::cout << ans << std::endl;

    return 0;
}
