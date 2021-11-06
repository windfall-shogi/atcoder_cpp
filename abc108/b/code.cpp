#include <iostream>

int main()
{
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;

    const int dx = x2 - x1, dy = y2 - y1;

    const int dx3 = -dy, dy3 = dx;
    const int x3 = x2 + dx3, y3 = y2 + dy3;

    const int dx4 = -dy3, dy4 = dx3;
    const int x4 = x3 + dx4, y4 = y3 + dy4;

    std::cout << x3 << ' ' << y3 << ' ' << x4 << ' ' << y4 << std::endl;

    return 0;
}
