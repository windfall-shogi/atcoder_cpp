#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }

    const auto it_min = std::min_element(arr.begin(), arr.end());
    const auto it_max = std::max_element(arr.begin(), arr.end());
    std::cout << *it_max - *it_min << std::endl;

    return 0;
}
