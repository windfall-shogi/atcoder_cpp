#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }

    std::sort(arr.begin(), arr.end());
    const int sum = std::accumulate(arr.rbegin(), arr.rbegin() + k, 0);
    std::cout << sum << std::endl;
    return 0;
}
