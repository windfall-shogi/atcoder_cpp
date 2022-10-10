#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> as(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> as[i];
    }

    std::vector<int> ans(n);
    int l = 0, r = as[0] + 1;
    while (true)
    {
        const int m = (l + r) / 2;
        ans[0] = 2 * m;
        int h = m;
        for (int i = 1; i < n; ++i)
        {
            int g = as[i - 1] - h;
            ans[i] = 2 * g;
            h = g;
        }
        if (h + m == as[n - 1])
        {
            break;
        }
        else if (h + m <= as[n - 1])
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        std::cout << ans[i];
        if (i == n - 1)
        {
            std::cout << std::endl;
        }
        else
        {
            std::cout << ' ';
        }
    }

    return 0;
}
