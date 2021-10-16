#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    int n, x;
    std::cin >> n >> x;
    std::vector<int> ms(n);
    int total = 0;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> ms[i];
        total += ms[i];
    }

    std::sort(ms.begin(), ms.end());
    std::cout << n + (x - total) / ms[0] << std::endl;

    return 0;
}
