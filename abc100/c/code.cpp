#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int64_t ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int64_t a;
        std::cin >> a;
        while (a % 2 == 0)
        {
            ++ans;
            a /= 2;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
