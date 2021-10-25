#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_set>

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> pairs;
    pairs.reserve(m);
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        --a;
        --b;
        pairs.emplace_back(b, a);
    }
    std::sort(pairs.begin(), pairs.end());

    std::unordered_set<int> cut;
    int current_b = -1;
    for (const auto &e : pairs)
    {
        if (current_b == e.first)
        {
            continue;
        }

        bool found = false;
        for (const int i : cut)
        {
            if (i >= e.second && i < e.first)
            {
                found = true;
                break;
            }
        }
        if (found)
        {
            continue;
        }

        current_b = e.first;
        cut.insert(e.first - 1);
    }

    std::cout << cut.size() << std::endl;

    return 0;
}
