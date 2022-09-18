#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <functional>

struct Stop
{
    int64_t x, t;

    Stop() = default;
    Stop(const int64_t x2, const int64_t t2) : x(x2), t(t2) {}

    bool operator<(const Stop &rhs) const
    {
        if (x == rhs.x)
        {
            return t < rhs.t;
        }
        else
        {
            return x < rhs.x;
        }
    }
    bool operator>(const Stop &rhs) const
    {
        if (x == rhs.x)
        {
            return t > rhs.t;
        }
        else
        {
            return x > rhs.x;
        }
    }
};

int main()
{
    int n, q;
    std::cin >> n >> q;
    std::vector<int64_t> ss(n), ts(n), xs(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> ss[i] >> ts[i] >> xs[i];
    }
    std::vector<int64_t> ds(q);
    for (int i = 0; i < q; ++i)
    {
        std::cin >> ds[i];
    }

    std::vector<std::pair<int64_t, Stop>> spans(n);
    for (int i = 0; i < n; ++i)
    {
        int64_t s = ss[i], t = ts[i], x = xs[i];
        s -= x;
        t -= x;

        spans[i] = std::make_pair(s, Stop{x, t});
    }
    std::sort(spans.begin(), spans.end());

    std::priority_queue<Stop, std::vector<Stop>, std::greater<Stop>> queue;
    auto it = spans.begin();
    for (const auto d : ds)
    {
        while (it != spans.end() && it->first <= d)
        {
            queue.push(it->second);
            ++it;
        }

        while (!queue.empty() && queue.top().t <= d)
        {
            queue.pop();
        }

        if (queue.empty())
        {
            std::cout << -1 << std::endl;
        }
        else
        {
            std::cout << queue.top().x << std::endl;
        }
    }

    return 0;
}
