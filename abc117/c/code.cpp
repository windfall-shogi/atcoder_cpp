#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<int64_t> xs(m);
    for (int i = 0; i < m; ++i)
    {
        std::cin >> xs[i];
    }

    if (n >= m)
    {
        std::cout << 0 << std::endl;
        return 0;
    }

    std::sort(xs.begin(), xs.end());
    std::priority_queue<int64_t, std::vector<int64_t>, std::greater<int64_t>> queue;
    for (int i = 0; i < m - 1; ++i)
    {
        queue.push(xs[i + 1] - xs[i]);
    }

    int64_t ans = 0;
    for (int i = 0; i < m - n; ++i)
    {
        ans += queue.top();
        queue.pop();
    }

    std::cout << ans << std::endl;

    return 0;
}
