#include <iostream>
#include <algorithm>

int main()
{
    int a, b, c, x, y;
    std::cin >> a >> b >> c >> x >> y;

    int sum = 0;
    if (a + b >= 2 * c)
    {
        const int k = std::min(x, y);
        sum += k * 2 * c;

        x -= k;
        y -= k;
        if (x > 0)
        {
            if (a >= 2 * c)
            {
                sum += x * 2 * c;
            }
            else
            {
                sum += x * a;
            }
        }
        else if (y > 0)
        {
            if (b >= 2 * c)
            {
                sum += y * 2 * c;
            }
            else
            {
                sum += y * b;
            }
        }
    }
    else
    {
        sum = x * a + y * b;
    }

    std::cout << sum << std::endl;

    return 0;
}
