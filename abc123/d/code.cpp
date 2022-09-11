#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main()
{
    int64_t x, y, z, k;
    std::cin >> x >> y >> z >> k;
    std::vector<int64_t> as(x), bs(y), cs(y);
    for (int64_t i = 0; i < x; ++i)
    {
        std::cin >> as[i];
    }
    for (int64_t i = 0; i < y; ++i)
    {
        std::cin >> bs[i];
    }
    for (int64_t i = 0; i < z; ++i)
    {
        std::cin >> cs[i];
    }

    std::vector<int64_t> buffer1;
    buffer1.reserve(x * y);
    for (const auto a : as)
    {
        for (const auto b : bs)
        {
            buffer1.emplace_back(a + b);
        }
    }
    std::sort(buffer1.rbegin(), buffer1.rend());
    std::sort(cs.rbegin(), cs.rend());

    std::priority_queue<int64_t> q;
    for (const auto c : cs)
    {
        if (q.size() >= k)
        {
            const auto current_min = -q.top();
            if (c + buffer1[0] <= current_min)
            {
                break;
            }
        }

        for (int64_t i = 0; i < std::min<int64_t>(k, buffer1.size()); ++i)
        {
            if (q.size() >= k)
            {
                const auto current_min = -q.top();
                const auto v = c + buffer1[i];
                if (v <= current_min)
                {
                    break;
                }

                q.pop();
                q.push(-v);
            }
            else
            {
                q.push(-(c + buffer1[i]));
            }
        }
    }

    std::vector<int64_t> buffer2;
    buffer2.reserve(q.size());
    while (!q.empty())
    {
        buffer2.emplace_back(-q.top());
        q.pop();
    }

    for (std::vector<int64_t>::const_reverse_iterator it = buffer2.rbegin(); it != buffer2.rend(); ++it)
    {
        std::cout << *it << std::endl;
    }

    return 0;
}
