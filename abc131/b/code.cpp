#include <iostream>

int main()
{
    int n, l;
    std::cin >> n >> l;
    int sum = (l - 1) * n + n * (n + 1) / 2;
    if (l >= 0)
    {
        sum -= l;
    }
    else if (l + n - 1 < 0)
    {
        sum -= l + n - 1;
    }
    std::cout << sum << std::endl;
    return 0;
}
