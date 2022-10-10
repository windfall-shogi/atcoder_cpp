#include <iostream>
#include <vector>
#include <cmath>

int main()
{
    int n, d;
    std::cin >> n >> d;
    std::vector<std::vector<int>> points(n);
    for (int i = 0; i < n; ++i)
    {
        points[i].resize(d);
        for (int j = 0; j < d; ++j)
        {
            std::cin >> points[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int distance = 0;
            for (int k = 0; k < d; ++k)
            {
                const auto tmp = points[i][k] - points[j][k];
                distance += tmp * tmp;
            }
            const auto tmp = static_cast<int>(std::sqrt(distance));
            if (tmp * tmp == distance)
            {
                ++ans;
            }
        }
    }
    std::cout << ans << std::endl;

    return 0;
}
