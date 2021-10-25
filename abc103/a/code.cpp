#include <iostream>
#include <array>
#include <algorithm>

int main()
{
    std::array<int, 3> as;
    for (auto it = as.begin(); it != as.end(); ++it)
    {
        std::cin >> *it;
    }
    std::sort(as.begin(), as.end());

    int cost = 0;
    for (int i = 0; i < 2; ++i)
    {
        cost += std::abs(as[i + 1] - as[i]);
    }

    std::cout << cost << std::endl;

    return 0;
}
