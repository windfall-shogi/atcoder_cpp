#include <iostream>

int main()
{
    int a, b;
    std::cin >> a >> b;
    int ans = 0;
    for (int i = 0; i < 2; ++i)
    {
        if (a > b)
        {
            ans += a;
            --a;
        }
        else
        {
            ans += b;
            --b;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
