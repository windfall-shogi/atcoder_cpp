#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> hs(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> hs[i];
    }

    int ans = 1;
    int current_max = hs[0];
    for (int i = 1; i < n; ++i)
    {
        if (hs[i] >= current_max)
        {
            ++ans;
            current_max = hs[i];
        }
    }

    std::cout << ans << std::endl;
    return 0;
}
