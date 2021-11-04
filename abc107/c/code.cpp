#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::vector<int64_t> left, right;
    left.reserve(n);
    right.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        int64_t x;
        std::cin >> x;
        if (x >= 0)
        {
            right.emplace_back(x);
        }
        else
        {
            left.emplace_back(-x);
        }
    }
    std::reverse(left.begin(), left.end());

    int64_t ans = std::numeric_limits<int64_t>::max();
    if (k <= static_cast<int>(left.size()))
    {
        ans = std::min(ans, left[k - 1]);
    }
    if (k <= static_cast<int>(right.size()))
    {
        ans = std::min(ans, right[k - 1]);
    }
    for (int i = std::max<int>(0, k - right.size() - 1); i < std::min<int>(left.size(), k - 1); ++i)
    {
        ans = std::min(ans, left[i] * 2 + right[k - i - 2]);
    }
    for (int i = std::max<int>(0, k - left.size() - 1); i < std::min<int>(right.size(), k - 1); ++i)
    {
        ans = std::min(ans, right[i] * 2 + left[k - i - 2]);
    }

    std::cout << ans << std::endl;

    return 0;
}
