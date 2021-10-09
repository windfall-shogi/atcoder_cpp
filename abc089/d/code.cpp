#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

int main()
{
    int h, w, d;
    std::cin >> h >> w >> d;
    std::vector<std::pair<int, int>> nums(h * w);
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            int a;
            std::cin >> a;
            --a;
            nums[a] = std::make_pair(i, j);
        }
    }

    std::vector<int> table(h * w, 0);
    for (int i = h * w - d - 1; i >= 0; --i)
    {
        const int j = i + d;

        const auto &pi = nums[i];
        const auto &pj = nums[j];
        table[i] = table[j] + std::abs(pi.first - pj.first) + std::abs(pi.second - pj.second);
    }

    int q;
    std::cin >> q;
    std::vector<int> result(q);
    for (int i = 0; i < q; ++i)
    {
        int l, r;
        std::cin >> l >> r;
        --l;
        --r;
        result[i] = table[l] - table[r];
    }

    for (int i = 0; i < q; ++i)
    {
        std::cout << result[i] << std::endl;
    }

    return 0;
}
