#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> ds(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> ds[i];
    }

    std::sort(ds.begin(), ds.end());
    const auto it = std::unique(ds.begin(), ds.end());
    const auto size = std::distance(ds.begin(), it);

    std::cout << size << std::endl;
    return 0;
}
