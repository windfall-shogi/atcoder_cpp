#include <iostream>

int main()
{
    int a, b, c, d, e, f;
    std::cin >> a >> b >> c >> d >> e >> f;

    int total = 100 * a, sugar = 0;
    for (int i = 0; 100 * a * i <= f; ++i)
    {
        for (int j = 0; 100 * (a * i + b * j) <= f; ++j)
        {
            const int w = 100 * (a * i + b * j);
            if (w == 0)
            {
                continue;
            }
            for (int k = 0; w + c * k <= f; ++k)
            {
                for (int l = 0; w + c * k + d * l <= f; ++l)
                {
                    const int s = c * k + d * l;
                    if (s == 0)
                    {
                        continue;
                    }
                    if (s > e * (a * i + b * j))
                    {
                        continue;
                    }

                    if (s * total >= sugar * (s + w))
                    {
                        total = w + s;
                        sugar = s;
                    }
                }
            }
        }
    }

    std::cout << total << ' ' << sugar << std::endl;
    return 0;
}
