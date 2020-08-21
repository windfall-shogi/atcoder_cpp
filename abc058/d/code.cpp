#include <iostream>
#include <vector>

int main()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<int> x_list(n), y_list(m);
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        x_list[i] = tmp;
    }
    for (int i = 0; i < m; ++i)
    {
        int tmp;
        std::cin >> tmp;
        y_list[i] = tmp;
    }

    int64_t sum_x = 0;
    for (int64_t i = 1; i <= n; ++i)
    {
        sum_x += (i - 1) * x_list[i - 1] - (n - i) * x_list[i - 1];
    }
    int64_t sum_y = 0;
    for (int64_t i = 1; i <= m; ++i)
    {
        sum_y += (i - 1) * y_list[i - 1] - (m - i) * y_list[i - 1];
    }

    constexpr int32_t MOD = 1000000007;

    sum_x %= MOD;
    sum_y %= MOD;

    const int64_t result = (sum_x * sum_y) % MOD;
    std::cout << result << std::endl;

    return 0;
}
