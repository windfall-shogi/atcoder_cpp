#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <functional>
#include <numeric>

struct Cake
{
    int64_t x, y, z;
};

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<Cake> data;
    data.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        int64_t x, y, z;
        std::cin >> x >> y >> z;
        data.emplace_back(Cake{x, y, z});
    }

    int64_t ans = std::numeric_limits<int64_t>::min();
    std::vector<int64_t> buffer(n);
    for (int i = 0; i < 8; ++i)
    {
        std::transform(data.begin(), data.end(), buffer.begin(), [i](const Cake &cake)
                       {
                           int64_t sum = 0;
                           sum += (i >> 0) % 2 ? cake.x : -cake.x;
                           sum += (i >> 1) % 2 ? cake.y : -cake.y;
                           sum += (i >> 2) % 2 ? cake.z : -cake.z;
                           return sum;
                       });
        std::nth_element(buffer.begin(), buffer.begin() + m, buffer.end(), std::greater<int64_t>());
        ans = std::max(ans, std::accumulate(buffer.begin(), buffer.begin() + m, static_cast<int64_t>(0)));
    }

    std::cout << ans << std::endl;

    return 0;
}
