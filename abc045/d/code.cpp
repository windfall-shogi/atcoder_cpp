#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>

int main()
{
    int h, w, n;
    std::cin >> h >> w >> n;
    std::unordered_map<int64_t, int> map;
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        // 0-baseに変換
        --a;
        --b;

        for (int p_h = std::max(a - 2, 0); p_h <= std::min(a, h - 3); ++p_h)
        {
            for (int p_w = std::max(b - 2, 0); p_w <= std::min(b, w - 3); ++p_w)
            {
                ++map[static_cast<int64_t>(p_h) * w + p_w];
            }
        }
    }

    std::vector<int64_t> count(10);
    count[0] = static_cast<int64_t>(h - 2) * (w - 2);
    for (std::unordered_map<int64_t, int>::const_iterator it = map.begin(); it != map.end(); ++it)
    {
        --count[0];
        ++count[it->second];
    }

    for (int i = 0; i < 10; ++i)
    {
        std::cout << count[i] << std::endl;
    }
    return 0;
}
