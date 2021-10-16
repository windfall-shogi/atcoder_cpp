#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>

int main()
{
    std::array<int, 3> v;
    for (int i = 0; i < 3; ++i)
    {
        std::cin >> v[i];
    }
    std::sort(v.begin(), v.end());

    int k;
    std::cin >> k;

    v[2] <<= k;

    std::cout << std::accumulate(v.begin(), v.end(), 0) << std::endl;

    return 0;
}
