#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    std::vector<int> non_dec;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
        if (arr[i] % 10 != 0)
        {
            non_dec.push_back(arr[i]);
        }
    }

    if (non_dec.empty())
    {
        std::cout << 0 << std::endl;
        return 0;
    }

    const int sum = std::accumulate(arr.begin(), arr.end(), 0);
    if (sum % 10 != 0)
    {
        std::cout << sum << std::endl;
        return 0;
    }

    std::sort(non_dec.begin(), non_dec.end());
    std::cout << sum - non_dec.front() << std::endl;
    return 0;
}
