#include <iostream>
#include <vector>
#include <limits>

int main()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<int> arr_a(n), arr_b(n), arr_c(m), arr_d(m);
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        arr_a[i] = a;
        arr_b[i] = b;
    }
    for (int i = 0; i < m; ++i)
    {
        int c, d;
        std::cin >> c >> d;
        arr_c[i] = c;
        arr_d[i] = d;
    }

    for (int i = 0; i < n; ++i)
    {
        const int a = arr_a[i], b = arr_b[i];
        int dist = std::numeric_limits<int>::max();
        int index = -1;
        for (int j = 0; j < m; ++j)
        {
            const int c = arr_c[j], d = arr_d[j];
            const int tmp = std::abs(a - c) + std::abs(b - d);
            if (tmp < dist)
            {
                dist = tmp;
                index = j;
            }
        }
        std::cout << index + 1 << std::endl;
    }
    return 0;
}
