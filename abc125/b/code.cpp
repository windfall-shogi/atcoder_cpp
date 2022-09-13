#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> vs(n), cs(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> vs[i];
    }
    for (int i = 0; i < n; ++i)
    {
        std::cin >> cs[i];
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (vs[i] > cs[i])
        {
            ans += vs[i] - cs[i];
        }
    }
    std::cout << ans << std::endl;

    return 0;
}
