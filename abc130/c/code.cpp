#include <iostream>
#include <algorithm>
#include <iomanip>

int main()
{
    int64_t w, h, x, y;
    std::cin >> w >> h >> x >> y;

    const double ans = w * h * 0.5;

    const int same = x * 2 == w && y * 2 == h ? 1 : 0;
    std::cout << ans << ' ' << std::defaultfloat << same << std::endl;
    return 0;
}
