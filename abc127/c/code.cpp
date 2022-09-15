#include <iostream>
#include <utility>

int main()
{
    int n, m;
    std::cin >> n >> m;
    int l_max = 0, r_min = n;
    for (int i = 0; i < m; ++i)
    {
        int l, r;
        std::cin >> l >> r;
        l_max = std::max(l_max, l);
        r_min = std::min(r_min, r);
    }
    std::cout << std::max(r_min - l_max + 1, 0) << std::endl;
    return 0;
}
