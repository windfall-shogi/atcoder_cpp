#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

int compute_cost(const std::vector<int> &arr, const int v)
{
    int cost = 0;
    std::for_each(arr.begin(), arr.end(), [&](const int a) {
        cost += (v - a) * (v - a);
    });
    return cost;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> arr;
    arr.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        arr.push_back(tmp);
    }

    const int sum = std::accumulate(arr.begin(), arr.end(), 0);
    const double mean = sum / static_cast<double>(n);

    const int cost1 = compute_cost(arr, static_cast<int>(std::floor(mean)));
    const int cost2 = compute_cost(arr, static_cast<int>(std::ceil(mean)));

    std::cout << std::min(cost1, cost2) << std::endl;
    return 0;
}
