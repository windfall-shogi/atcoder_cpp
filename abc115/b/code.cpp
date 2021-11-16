#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> ps(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> ps[i];
    }

    const int sum = std::accumulate(ps.begin(), ps.end(), 0);
    const auto it = std::max_element(ps.begin(), ps.end());
    const int ans = sum - *it / 2;

    std::cout << ans << std::endl;

    return 0;
}
