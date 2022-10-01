#include <iostream>
#include <vector>

int main()
{
    int n, q;
    std::cin >> n >> q;
    std::vector<std::vector<int>> as(n);
    for (int i = 0; i < n; ++i)
    {
        int l;
        std::cin >> l;
        as[i].reserve(l);
        for (int j = 0; j < l; ++j)
        {
            std::cin >> as[i][j];
        }
    }

    for (int k = 0; k < q; ++k)
    {
        int s, t;
        std::cin >> s >> t;
        std::cout << as[s - 1][t - 1] << std::endl;
    }

    return 0;
}
