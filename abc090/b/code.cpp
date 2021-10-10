#include <iostream>

int main()
{
    int a, b;
    std::cin >> a >> b;

    int ans = 0;
    for (int i = a / 10000; i <= 9; ++i)
    {
        const int v1 = i * 10001;
        if (v1 > b)
        {
            break;
        }
        for (int j = 0; j <= 9; ++j)
        {
            const int v2 = v1 + j * 1010;
            if (v2 > b)
            {
                break;
            }
            for (int k = 0; k <= 9; ++k)
            {
                const int v3 = v2 + k * 100;
                if (v3 >= a && v3 <= b)
                {
                    ++ans;
                }
            }
        }
    }

    std::cout << ans << std::endl;
    return 0;
}
