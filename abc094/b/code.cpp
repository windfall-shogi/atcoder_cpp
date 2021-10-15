#include <iostream>
#include <algorithm>

int main()
{
    int n, m, x;
    std::cin >> n >> m >> x;
    int left = 0, right = 0;
    for (int i = 0; i < m; ++i)
    {
        int a;
        std::cin >> a;
        if (a < x)
        {
            ++left;
        }
        else
        {
            ++right;
        }
    }

    std::cout << std::min(left, right) << std::endl;
    return 0;
}
