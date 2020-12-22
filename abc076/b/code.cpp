#include <iostream>

int main()
{
    int n, k;
    std::cin >> n >> k;
    int v = 1;
    for (int i = 0; i < n; ++i)
    {
        if (2 * v > v + k)
        {
            v += k;
        }
        else
        {
            v *= 2;
        }
    }
    std::cout << v << std::endl;
    return 0;
}
