#include <iostream>

int main()
{
    int n, x;
    std::cin >> n >> x;
    int ans = x >= 0 ? 1 : 0;
    int d = 0;
    for (int i = 0; i < n; ++i)
    {
        int l;
        std::cin >> l;
        d += l;
        if (x >= d)
        {
            ++ans;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
