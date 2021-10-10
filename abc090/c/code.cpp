#include <iostream>

int main()
{
    int64_t n, m;
    std::cin >> n >> m;

    if (m > n)
    {
        int64_t tmp = m;
        m = n;
        n = tmp;
    }

    int64_t ans = 0;
    if (m == 1)
    {
        if (n == 1)
        {
            ans = 1;
        }
        else
        {
            ans = n - 2;
        }
    }
    else if (m == 2)
    {
        ans = 0;
    }
    else
    {
        ans = (m - 2) * (n - 2);
    }

    std::cout << ans << std::endl;
    return 0;
}
