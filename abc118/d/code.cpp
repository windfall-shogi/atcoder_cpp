#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

constexpr int K[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<int> as(m);
    for (int i = 0; i < m; ++i)
    {
        std::cin >> as[i];
    }
    std::sort(as.begin(), as.end());

    std::unordered_map<int, std::string> table;
    for (const auto a : as)
    {
        table[K[a]] = std::to_string(a);
    }

    for (int i = 2; i <= n; ++i)
    {
        for (const auto a : as)
        {
            const auto j = i - K[a];
            if (j < 0 || table.find(j) == table.end())
            {
                continue;
            }

            const std::string tmp = std::to_string(a) + table[j];
            if (table[i].empty() || tmp.size() > table[i].size() ||
                (tmp.size() == table[i].size() && tmp > table[i]))
            {
                table[i] = tmp;
            }
        }
    }

    std::cout << table[n] << std::endl;

    return 0;
}
