#include <iostream>
#include <array>
#include <algorithm>

int main()
{
    std::array<int, 3> vec;
    for (int i = 0; i < 3; ++i)
    {
        std::cin >> vec[i];
    }
    std::sort(vec.begin(), vec.end());

    const int a = vec[0], b = vec[1], c = vec[2];
    int ans;
    if ((b - a) % 2 == 1)
    {
        ans = (b - a) / 2 + 1 + c + 1 - b;
    }
    else
    {
        ans = (b - a) / 2 + c - b;
    }

    std::cout << ans << std::endl;
    return 0;
}
