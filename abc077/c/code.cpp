#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> as(n), bs(n), cs(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> as[i];
    }
    for (int i = 0; i < n; ++i)
    {
        std::cin >> bs[i];
    }
    for (int i = 0; i < n; ++i)
    {
        std::cin >> cs[i];
    }

    std::sort(as.begin(), as.end());
    std::sort(bs.begin(), bs.end());
    std::sort(cs.begin(), cs.end());

    uint64_t count = 0;
    for (const auto b : bs)
    {
        const auto na = std::distance(as.begin(), std::lower_bound(as.begin(), as.end(), b));
        const auto nc = std::distance(std::upper_bound(cs.begin(), cs.end(), b), cs.end());
        count += na * nc;
    }

    std::cout << count << std::endl;
    return 0;
}
