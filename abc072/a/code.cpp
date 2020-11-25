#include <iostream>
#include <algorithm>

int main()
{
    int x, t;
    std::cin >> x >> t;
    std::cout << std::max(x - t, 0) << std::endl;
    return 0;
}
