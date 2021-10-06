#include <iostream>

void solve(const int n, const int y, int &a, int &b, int &c)
{
    for (int i = 0; i <= std::min(n, y / 10000); ++i)
    {
        int value = y - i * 10000;
        for (int j = 0; j <= std::min(n - i, value / 5000); ++j)
        {
            const int k = n - i - j;
            if (i * 10000 + j * 5000 + k * 1000 == y)
            {
                a = i;
                b = j;
                c = k;

                return;
            }
        }
    }

    a = b = c = -1;
    return;
}

int main()
{
    int n, y;
    std::cin >> n >> y;

    int a, b, c;
    solve(n, y, a, b, c);

    std::cout << a << ' ' << b << ' ' << c << std::endl;
    return 0;
}
