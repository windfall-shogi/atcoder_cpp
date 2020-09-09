#include <iostream>
#include <vector>

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<int> counts(n);
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        --a;
        --b;
        ++counts[a];
        ++counts[b];
    }

    for (int i = 0; i < n; ++i)
    {
        std::cout << counts[i] << std::endl;
    }
    return 0;
}
