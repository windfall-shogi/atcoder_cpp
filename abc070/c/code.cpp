#include <iostream>
#include <vector>
#include <numeric>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int64_t> arr(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }

    int64_t ans = 1;
    for (const auto v : arr)
    {
        ans = std::lcm(ans, v); // c++17
    }

    std::cout << ans << std::endl;
    return 0;
}
