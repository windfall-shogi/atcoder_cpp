#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>

int find(std::vector<int> &parents, const int x)
{
    if (parents[x] == x)
    {
        return x;
    }
    else
    {
        return parents[x] = find(parents, parents[x]);
    }
}

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

    constexpr int64_t n = 1LL << 20;
    std::vector<int> parents(n);
    std::vector<int64_t> value(n, -1);
    std::iota(begin(parents), end(parents), 0);

    for (int i = 0; i < q; ++i)
    {
        int64_t h = xs[i] % n;
        if (ts[i] == 1)
        {
            h = find(parents, h);
            value[h] = xs[i];
            parents[h] = find(parents, (h + 1) % n);
        }
        else
        {
            std::cout << value[h] << std::endl;
        }
    }

    return 0;
}
