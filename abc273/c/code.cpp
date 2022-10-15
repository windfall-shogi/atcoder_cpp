#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int64_t> as(n), bs(n), cs(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> as[i];
        bs[i] = as[i];
    }
    std::sort(bs.begin(), bs.end());
    bs.erase(std::unique(bs.begin(), bs.end()), bs.end());

    for (int i = 0; i < n; ++i)
    {
        const auto it = std::upper_bound(bs.begin(), bs.end(), as[i]);
        const auto d = std::distance(it, bs.end());
        ++cs[d];
    }

    for (const auto c : cs)
    {
        std::cout << c << std::endl;
    }

    return 0;
}
