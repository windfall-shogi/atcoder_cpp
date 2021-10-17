#include <iostream>

int main()
{
    int x;
    std::cin >> x;
    int ans = 1;
    for (int b = 2; b * b <= x; ++b)
    {
        int tmp = b * b;
        while (true)
        {
            if (tmp > ans)
            {
                ans = tmp;
            }
            tmp *= b;
            if (tmp > x)
            {
                break;
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
