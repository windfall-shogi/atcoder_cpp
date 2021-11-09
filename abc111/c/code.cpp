#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    std::unordered_map<int, int> map1, map2;
    for (int i = 0; i < n; i += 2)
    {
        int v1, v2;
        std::cin >> v1 >> v2;
        ++map1[v1];
        ++map2[v2];
    }

    std::vector<std::pair<int, int>> vec1, vec2;
    vec1.reserve(map1.size());
    vec2.reserve(map2.size());
    for (const auto &e : map1)
    {
        vec1.emplace_back(e.second, e.first);
    }
    for (const auto &e : map2)
    {
        vec2.emplace_back(e.second, e.first);
    }
    std::sort(vec1.begin(), vec1.end());
    std::sort(vec2.begin(), vec2.end());

    if (vec1.size() > vec2.size())
    {
        vec1.swap(vec2);
    }

    int ans = 0;
    if (vec1.back().second != vec2.back().second)
    {
        ans = n - vec1.back().first - vec2.back().first;
    }
    else if (vec1.size() == 1 && vec2.size() == 1)
    {
        ans = n / 2;
    }
    else if (vec1.size() == 1)
    {
        ans = n / 2 - vec2[vec2.size() - 2].first;
    }
    else
    {
        const int k1 = vec1[vec1.size() - 2].first;
        const int k2 = vec2[vec2.size() - 2].first;
        ans = std::min(n - vec1.back().first - k2,
                       n - k1 - vec2.back().first);
    }

    std::cout << ans << std::endl;

    return 0;
}
