#include <iostream>
#include <algorithm>

int main()
{
    int a, b, k;
    std::cin >> a >> b >> k;
    for (int i = a; i <= std::min(a + k - 1, b); ++i)
    {
        std::cout << i << std::endl;
    }
    for (int i = std::max(a + k, b - k + 1); i <= b; ++i)
    {
        std::cout << i << std::endl;
    }
    return 0;
}
