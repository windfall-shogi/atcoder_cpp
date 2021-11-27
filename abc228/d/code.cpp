#include <iostream>
#include <vector>
#include <unordered_map>

int main()
{
    int q;
    std::cin >> q;
    std::vector<int> ts(q);
    std::vector<int64_t> xs(q);
    for (int i = 0; i < q; ++i)
    {
        std::cin >> ts[i] >> xs[i];
    }

    std::unordered_map<int, int64_t> m;

    constexpr int64_t n = 1LL << 20;
    for (int i = 0; i < q; ++i)
    {
        int64_t h = xs[i] % n;
        if (ts[i] == 1)
        {
            std::unordered_map<int, int64_t>::iterator it;
            while (true)
            {
                it = m.find(h);
                if (it == m.end())
                {
                    break;
                }
                ++h;
                h %= n;
            }
            m[h] = xs[i];
        }
        else
        {
            const auto it = m.find(h);
            std::cout << (it == m.end() ? -1 : m[h]) << std::endl;
        }
    }

    return 0;
}
