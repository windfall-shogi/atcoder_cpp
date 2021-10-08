#include <iostream>

int main()
{
    int a, b, c, x;
    std::cin >> a >> b >> c >> x;

    int ans = 0;
    for (int i = 0; i <= a; ++i)
    {
        const int v0 = i * 500;
        if (v0 > x)
        {
            break;
        }

        for (int j = 0; j <= b; ++j)
        {
            const int v1 = 100 * j;
            const int y = x - v0 - v1;
            if (y < 0)
            {
                break;
            }

            if (y % 50 == 0 && y / 50 <= c)
            {
                ++ans;
            }
        }
    }

    std::cout << ans << std::endl;
    return 0;
}
