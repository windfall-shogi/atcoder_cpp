#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::vector<int> hs(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> hs[i];
    }

    std::sort(hs.begin(), hs.end());
    int ans = hs.back();
    for (int i = 0; i <= n - k; ++i)
    {
        ans = std::min(ans, hs[i + k - 1] - hs[i]);
    }

    std::cout << ans << std::endl;

    return 0;
}
