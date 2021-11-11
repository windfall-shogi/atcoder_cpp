#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n, t, a;
    std::cin >> n >> t >> a;
    t *= 1000;
    a *= 1000;
    std::vector<int> values(n);
    for (int i = 0; i < n; ++i)
    {
        int h;
        std::cin >> h;
        values[i] = std::abs(a - (t - h * 6));
    }

    const auto it = std::min_element(values.begin(), values.end());
    const auto ans = std::distance(values.begin(), it) + 1;

    std::cout << ans << std::endl;

    return 0;
}
