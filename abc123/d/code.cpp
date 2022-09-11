#include <iostream>
#include <vector>
#include <queue>

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

    std::priority_queue<int64_t> q;
    for (const auto a : as)
    {
        for (const auto b : bs)
        {
            for (const auto c : cs)
            {
                q.push(a + b + c);
            }
        }
    }

    for (int64_t i = 0; i < k; ++i)
    {
        std::cout << q.top() << std::endl;
        q.pop();
    }

    return 0;
}
