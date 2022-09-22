#include <iostream>
#include <vector>
#include <numeric>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> ws(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> ws[i];
    }

    const auto sum = std::accumulate(ws.begin(), ws.end(), 0);
    int ans = sum;
    int left = 0;
    for (int i = 0; i < n; ++i)
    {
        left += ws[i];
        const int right = sum - left;
        ans = std::min(ans, std::abs(right - left));
    }
    std::cout << ans << std::endl;

    return 0;
}
