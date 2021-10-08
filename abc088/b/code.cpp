#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> as(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> as[i];
    }

    std::sort(as.begin(), as.end(), std::greater<int>());
    int alice = 0, bob = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i % 2 == 0)
        {
            alice += as[i];
        }
        else
        {
            bob += as[i];
        }
    }

    std::cout << alice - bob << std::endl;
    return 0;
}
