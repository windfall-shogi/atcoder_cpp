#include <iostream>
#include <algorithm>

int main()
{
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    const auto first = std::max(a, c);
    const auto last = std::min(b, d);
    const auto duration = std::max(last - first, 0);
    std::cout << duration << std::endl;
    return 0;
}
