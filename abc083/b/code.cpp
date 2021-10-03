#include <iostream>

bool check(int x, const int a, const int b)
{
    int sum = 0;
    do
    {
        sum += x % 10;
        x /= 10;
    } while (x > 0);
    return sum >= a && sum <= b;
}

int main()
{
    int n, a, b;
    std::cin >> n >> a >> b;

    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (check(i, a, b))
        {
            sum += i;
        }
    }

    std::cout << sum << std::endl;
    return 0;
}
