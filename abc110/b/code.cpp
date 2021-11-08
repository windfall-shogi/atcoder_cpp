#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n, m, x, y;
    std::cin >> n >> m >> x >> y;
    std::vector<int> xs(n), ys(m);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> xs[i];
    }
    for (int i = 0; i < m; ++i)
    {
        std::cin >> ys[i];
    }

    std::sort(xs.begin(), xs.end());
    std::sort(ys.begin(), ys.end());

    const bool flag = x < y && xs.back() < ys.front() && xs.back() < y && x < ys.front();
    std::cout << (flag ? "No War" : "War") << std::endl;

    return 0;
}
