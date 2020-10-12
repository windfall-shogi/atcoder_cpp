#include <iostream>
#include <algorithm>

int main()
{
    int a, b, c;
    std::cin >> a >> b >> c;
    const int ans = a + b + c - std::max({a, b, c});
    std::cout << ans << std::endl;
    return 0;
}
