#include <iostream>
#include <algorithm>

int main()
{
    int p, q, r;
    std::cin >> p >> q >> r;
    std::cout << std::min({p + q, q + r, r + p}) << std::endl;
    return 0;
}
