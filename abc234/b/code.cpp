#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>

int main()
{
    int64_t N;
    std::cin >> N;
    std::vector<double> xs(N), ys(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> xs[i] >> ys[i];
    }

    double ans = 0;
    for (int i = 0; i < N - 1; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            const double tmp = std::sqrt(std::pow(xs[i] - xs[j], 2) + std::pow(ys[i] - ys[j], 2));
            ans = std::max(tmp, ans);
        }
    }
    std::cout << std::setprecision(15) << ans << std::endl;
    ;
    return 0;
}
