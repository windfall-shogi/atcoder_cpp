#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int64_t prev1 = 1, prev2 = 2;
    int64_t l = 0;
    if (n == 1)
    {
        l = 1;
    }
    else
    {
        for (int i = 2; i <= n; ++i)
        {
            l = prev1 + prev2;
            prev2 = prev1;
            prev1 = l;
        }
    }

    std::cout << l << std::endl;
    return 0;
}
