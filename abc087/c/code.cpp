#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> as(2);
    for (int i = 0; i < 2; ++i)
    {
        as[i].resize(n);
        for (int j = 0; j < n; ++j)
        {
            std::cin >> as[i][j];
        }
    }

    std::vector<int> upper(n), lower(n);
    std::partial_sum(as[0].begin(), as[0].end(), upper.begin());
    std::partial_sum(as[1].rbegin(), as[1].rend(), lower.rbegin());

    std::vector<int> sum(n);
    std::transform(upper.begin(), upper.end(), lower.begin(), sum.begin(), [](const int a, const int b)
                   { return a + b; });
    const auto it = std::max_element(sum.begin(), sum.end());

    std::cout << *it << std::endl;
    return 0;
}
