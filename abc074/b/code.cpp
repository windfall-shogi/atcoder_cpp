#include <iostream>
#include <utility>

int main()
{
    int n, k;
    std::cin >> n >> k;
    int total = 0;
    for (int i = 0; i < n; ++i)
    {
        int x;
        std::cin >> x;

        total += 2 * std::min(x, k - x);
    }
    std::cout << total << std::endl;
    return 0;
}
