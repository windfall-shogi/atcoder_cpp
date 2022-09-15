#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>

int main()
{
    int64_t n, m;
    std::cin >> n >> m;
    std::vector<int64_t> as(n);
    for (int64_t i = 0; i < n; ++i)
    {
        std::cin >> as[i];
    }
    std::sort(as.begin(), as.end());
    std::vector<std::pair<int64_t, int64_t>> bs(m);
    for (int64_t i = 0; i < m; ++i)
    {
        int64_t b, c;
        std::cin >> b >> c;
        bs[i] = std::make_pair(c, b);
    }
    std::sort(bs.rbegin(), bs.rend());

    int64_t i = 0;
    for (const auto &e : bs)
    {
        const auto c = e.first;
        auto b = e.second;

        bool flag = true;
        for (; i < n && b > 0; ++i)
        {
            if (as[i] < c)
            {
                as[i] = c;
                --b;
            }
            else
            {
                flag = false;
                break;
            }
        }
        if (!flag)
        {
            break;
        }
    }
    std::cout << std::accumulate(as.begin(), as.end(), 0LL) << std::endl;
    return 0;
}
