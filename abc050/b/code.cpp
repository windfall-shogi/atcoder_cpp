#include <iostream>
#include <vector>
#include <numeric>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> t_arr(n);
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        t_arr[i] = tmp;
    }

    int m;
    std::cin >> m;
    std::vector<int> p_arr(m);
    std::vector<int> x_arr(m);
    for (int i = 0; i < m; ++i)
    {
        int p, x;
        std::cin >> p >> x;
        p_arr[i] = --p;
        x_arr[i] = x;
    }

    const int64_t sum = std::accumulate(t_arr.begin(), t_arr.end(), static_cast<int64_t>(0));
    for (int i = 0; i < m; ++i)
    {
        const int p = p_arr[i];
        std::cout << sum - (t_arr[p] - x_arr[i]);
        if (i != m - 1)
        {
            std::cout << std::endl;
        }
    }

    return 0;
}
