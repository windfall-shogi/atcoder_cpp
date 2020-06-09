#include <iostream>
#include <algorithm>

int main()
{
    int w, h, n;
    std::cin >> w >> h >> n;

    int x_l = 0, x_u = w, y_l = 0, y_u = h;
    for (int i = 0; i < n; ++i)
    {
        int x, y, a;
        std::cin >> x >> y >> a;
        switch (a)
        {
        case 1:
            x_l = std::max(x, x_l);
            break;
        case 2:
            x_u = std::min(x, x_u);
            break;
        case 3:
            y_l = std::max(y, y_l);
            break;
        case 4:
            y_u = std::min(y, y_u);
            break;
        default:
            break;
        }
    }
    if (x_l >= x_u || y_l >= y_u)
    {
        std::cout << 0 << std::endl;
    }
    else
    {
        std::cout << (x_u - x_l) * (y_u - y_l) << std::endl;
    }
    return 0;
}
