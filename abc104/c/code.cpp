#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int d, g;
    std::cin >> d >> g;
    g /= 100;
    std::vector<int> ps(d), cs(d);
    for (int i = 0; i < d; ++i)
    {
        std::cin >> ps[i] >> cs[i];
        cs[i] /= 100;
    }

    int ans = 1 << 30;
    for (int i = 0; i < (1 << d); ++i)
    {
        int score = 0;
        int count = 0;
        for (int j = 0; j < d; ++j)
        {
            if (i & (1 << j))
            {
                score += ps[j] * (j + 1) + cs[j];
                count += ps[j];
            }
        }
        if (score >= g)
        {
            ans = std::min(ans, count);
            continue;
        }
        
        for (int j = d - 1; j >= 0; --j)
        {
            if (!(i & (1 << j)))
            {
                const int tmp = std::min((g - score + j) / (j + 1), ps[j] - 1);
                score += tmp * (j + 1);
                count += tmp;

                if (score >= g)
                {
                    break;
                }
            }
        }

        if (score >= g)
        {
            ans = std::min(ans, count);
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
