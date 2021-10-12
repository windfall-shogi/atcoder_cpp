#include <iostream>
#include <vector>
#include <numeric>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> as(n + 2);
    as[0] = 0;
    as[n + 1] = 0;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> as[i + 1];
    }

    std::vector<int> normal_cost(n + 1);
    for (int i = 0; i <= n; ++i)
    {
        normal_cost[i] = std::abs(as[i + 1] - as[i]);
    }
    const int sum = std::accumulate(normal_cost.begin(), normal_cost.end(), 0);

    std::vector<int> skip_cost(n);
    for (int i = 0; i < n; ++i)
    {
        skip_cost[i] = std::abs(as[i + 2] - as[i]);
    }

    for (int i = 0; i < n; ++i)
    {
        std::cout << sum - (normal_cost[i] + normal_cost[i + 1]) + skip_cost[i] << std::endl;
    }

    return 0;
}
