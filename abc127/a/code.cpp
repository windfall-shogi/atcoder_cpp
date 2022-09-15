#include <iostream>

int main()
{
    int a, b;
    std::cin >> a >> b;
    int ans;
    if (a >= 13)
    {
        ans = b;
    }
    else if (a >= 6 && a <= 12)
    {
        ans = b / 2;
    }
    else
    {
        ans = 0;
    }
    std::cout << ans << std::endl;
    return 0;
}
