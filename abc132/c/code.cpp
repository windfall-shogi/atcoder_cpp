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
    int m = n / 2;
    std::cout << ds[m] - ds[m - 1] << std::endl;

    return 0;
}
