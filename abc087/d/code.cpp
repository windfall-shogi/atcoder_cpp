#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

bool check(const int a, const std::vector<int64_t> &xs, const std::unordered_map<int, int> &map)
{
    for (const auto &e : map)
    {
        if (xs[e.first] == std::numeric_limits<int64_t>::max())
        {
            continue;
        }

        if (xs[e.first] - xs[a] != e.second)
        {
            return false;
        }
    }
    return true;
}

bool search(const std::vector<std::unordered_map<int, int>> &maps, std::vector<int64_t> &xs,
            const int start, std::vector<bool> &registered, std::unordered_set<int> &unused)
{
    std::queue<int> q;
    q.push(start);
    registered[start] = true;
    xs[start] = 0;
    unused.erase(start);

    while (!q.empty())
    {
        const int a = q.front();
        q.pop();

        for (const auto &m : maps[a])
        {
            if (!registered[m.first])
            {
                xs[m.first] = m.second + xs[a];
                if (!check(m.first, xs, maps[m.first]))
                {
                    return false;
                }

                registered[m.first] = true;
                q.push(m.first);
                unused.erase(m.first);
            }
        }
    }
    return true;
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::unordered_map<int, int>> maps(n);
    for (int i = 0; i < m; ++i)
    {
        int l, r, d;
        std::cin >> l >> r >> d;
        --l;
        --r;

        maps[l].emplace(r, d);
        maps[r].emplace(l, -d);
    }

    std::vector<int64_t> xs(n, std::numeric_limits<int64_t>::max());
    std::vector<bool> registered(n, false);
    std::unordered_set<int> unused;
    for (int i = 0; i < n; ++i)
    {
        unused.emplace(i);
    }

    int start = 0;
    bool result;
    while (true)
    {
        result = search(maps, xs, start, registered, unused);
        if (!result)
        {
            break;
        }
        if (unused.empty())
        {
            break;
        }
        else
        {
            start = *unused.begin();
        }
    }

    std::cout << (result ? "Yes" : "No") << std::endl;
    return 0;
}
