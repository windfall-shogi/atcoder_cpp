#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<int> counter(m);
    for (int i = 0; i < n; ++i)
    {
        int k;
        std::cin >> k;
        for (int j = 0; j < k; ++j)
        {
            int a;
            std::cin >> a;
            --a;
            ++counter[a];
        }
    }

    const auto ans = std::count(counter.begin(), counter.end(), n);
    std::cout << ans << std::endl;

    return 0;
}
