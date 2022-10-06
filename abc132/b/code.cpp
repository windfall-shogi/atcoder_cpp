#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> ps(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> ps[i];
    }

    int ans = 0;
    for (int i = 1; i < n - 1; ++i)
    {
        if (ps[i + 1] > ps[i] && ps[i] > ps[i - 1])
        {
            ++ans;
        }
        else if (ps[i - 1] > ps[i] && ps[i] > ps[i + 1])
        {
            ++ans;
        }
    }
    std::cout << ans << std::endl;

    return 0;
}
