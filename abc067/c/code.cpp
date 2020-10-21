#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int64_t> arr(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }

    const int64_t total = std::accumulate(arr.begin(), arr.end(), 0ll);
    int64_t a = 0, b = total;
    int64_t diff = std::numeric_limits<int64_t>::max();
    for (int i = 0; i < n - 1; ++i)
    {
        a += arr[i];
        b -= arr[i];

        diff = std::min(diff, std::abs(a - b));
    }

    std::cout << diff << std::endl;
    return 0;
}
