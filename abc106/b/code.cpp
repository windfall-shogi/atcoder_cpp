#include <iostream>

int count(const int x)
{
    if (x % 2 == 0)
    {
        return 0;
    }

    int ans = 2;
    for (int i = 3; i * i <= x; i += 2)
    {
        if (x % i == 0)
        {
            if (i * i != x)
            {
                ans += 2;
            }
            else
            {
                ans += 1;
            }
        }
    }
    return ans;
}

int main()
{
    int n;
    std::cin >> n;

    int ans = 0;
    for (int i = 3; i <= n; ++i)
    {
        if (count(i) == 8)
        {
            ++ans;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
