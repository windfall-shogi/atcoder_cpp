#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <utility>

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::vector<std::pair<int64_t, int64_t>> points(n);
    std::vector<int64_t> xs(n), ys(n);
    for (int i = 0; i < n; ++i)
    {
        int64_t x, y;
        std::cin >> x >> y;
        points[i] = std::make_pair(x, y);
        xs[i] = x;
        ys[i] = y;
    }

    std::sort(xs.begin(), xs.end());
    std::sort(ys.begin(), ys.end());

    int64_t area = (xs.back() - xs.front()) * (ys.back() - ys.front());
    for (int64_t xi = 0; xi < n - 1; ++xi)
    {
        for (int64_t xj = xi + 1; xj < n; ++xj)
        {
            for (int64_t yi = 0; yi < n - 1; ++yi)
            {
                for (int64_t yj = yi + 1; yj < n; ++yj)
                {
                    const int64_t x_min = xs[xi], x_max = xs[xj], y_min = ys[yi], y_max = ys[yj];

                    int count = 0;
                    for (int i = 0; i < n; ++i)
                    {
                        const int64_t x = points[i].first, y = points[i].second;
                        if (x >= x_min && x <= x_max && y >= y_min && y <= y_max)
                        {
                            ++count;
                        }
                    }
                    if (count >= k)
                    {
                        area = std::min(area, (x_max - x_min) * (y_max - y_min));
                    }
                }
            }
        }
    }

    std::cout << area << std::endl;
    return 0;
}
