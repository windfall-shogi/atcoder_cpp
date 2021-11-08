#include <iostream>
#include <array>
#include <algorithm>

int main()
{
    std::array<int, 3> values;
    for (int i = 0; i < 3; ++i)
    {
        std::cin >> values[i];
    }
    std::sort(values.begin(), values.end());
    std::cout << values[2] * 10 + values[1] + values[0] << std::endl;
    return 0;
}
