#include <iostream>
#include <cmath>

int main()
{
    int deg, dis;
    std::cin >> deg >> dis;
    // degは10倍されている
    // 小数点以下2桁までを整数で扱うためにさらに10倍する
    deg *= 10;

    int d = static_cast<int>(std::round(dis * 10.0 / 60.0));
    // 風力
    int w;
    if (d <= 2)
    {
        w = 0;
    }
    else if (d >= 3 && d <= 15)
    {
        w = 1;
    }
    else if (d >= 16 && d <= 33)
    {
        w = 2;
    }
    else if (d >= 34 && d <= 54)
    {
        w = 3;
    }
    else if (d >= 55 && d <= 79)
    {
        w = 4;
    }
    else if (d >= 80 && d <= 107)
    {
        w = 5;
    }
    else if (d >= 108 && d <= 138)
    {
        w = 6;
    }
    else if (d >= 139 && d <= 171)
    {
        w = 7;
    }
    else if (d >= 172 && d <= 207)
    {
        w = 8;
    }
    else if (d >= 208 && d <= 244)
    {
        w = 9;
    }
    else if (d >= 245 && d <= 284)
    {
        w = 10;
    }
    else if (d >= 285 && d <= 326)
    {
        w = 11;
    }
    else if (d >= 327)
    {
        w = 12;
    }
    else
    {
        w = -1;
    }

    if (w == 0)
    {
        std::cout << "C 0" << std::endl;
        return 0;
    }

    constexpr char DEG[][4] = {
        "N", "NNE", "NE", "ENE", //
        "E", "ESE", "SE", "SSE", //
        "S", "SSW", "SW", "WSW", //
        "W", "WNW", "NW", "NNW"};
    deg += 1125;
    if (deg >= 36000)
    {
        deg -= 36000;
    }
    const int i = deg / 2250;

    std::cout << DEG[i] << ' ' << w << std::endl;
    return 0;
}
