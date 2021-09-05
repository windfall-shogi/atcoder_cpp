#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::unordered_map<int, int> counter;
    for (int i = 0; i < n; ++i)
    {
        int a;
        std::cin >> a;
        ++counter[a];
    }

    if (counter.size() <= k)
    {
        std::cout << 0 << std::endl;
        return 0;
    }
    // 数字ごとにまとめた個数の配列
    std::vector<int> v;
    v.reserve(counter.size());
    for (const auto &e : counter)
    {
        v.emplace_back(e.second);
    }

    std::sort(v.begin(), v.end());
    int sum = 0;
    for (int i = 0; i < v.size() - k; ++i)
    {
        sum += v[i];
    }

    std::cout << sum << std::endl;

    return 0;
}
