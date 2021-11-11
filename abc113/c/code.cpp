#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <ios>
#include <iomanip>

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<int> ps(m), ys(m);
    std::vector<std::vector<int>> table(n);
    for (int i = 0; i < m; ++i)
    {
        std::cin >> ps[i] >> ys[i];

        table[ps[i] - 1].emplace_back(ys[i]);
    }

    std::unordered_map<int, int> map;
    for (auto &v : table)
    {
        std::sort(v.begin(), v.end());
        for (int i = 0; i < static_cast<int>(v.size()); ++i)
        {
            map.emplace(v[i], i + 1);
        }
    }

    for (int i = 0; i < m; ++i)
    {
        std::cout << std::setfill('0') << std::right << std::setw(6) << ps[i]
                  << std::setfill('0') << std::right << std::setw(6) << map[ys[i]] << std::endl;
    }

    return 0;
}
