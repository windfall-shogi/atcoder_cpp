#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#include <functional>

using Range = std::pair<int64_t, int64_t>;

int main()
{
    int64_t N, D;
    std::cin >> N >> D;
    std::priority_queue<Range, std::vector<Range>, std::greater<Range>> pq;
    for (int64_t i = 0; i < N; ++i)
    {
        int64_t l, r;
        std::cin >> l >> r;
        pq.push(std::make_pair(r, l));
    }

    int64_t ans = 0;
    int64_t done = -1;
    while (true)
    {
        while (!pq.empty() && pq.top().second <= done)
        {
            pq.pop();
        }
        if (pq.empty())
        {
            break;
        }

        done = pq.top().first + D - 1;
        ++ans;
    }

    std::cout << ans << std::endl;

    return 0;
}
