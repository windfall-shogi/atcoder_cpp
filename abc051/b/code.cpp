#include <iostream>
#include <algorithm>

int main()
{
    int k, s;
    std::cin >> k >> s;

    int count = 0;
    for (int x = 0; x <= std::min(s, k); ++x)
    {
        const int tmp = s - x;
        if (tmp > 2 * k)
        {
            continue;
        }
        if (tmp <= k)
        {
            count += tmp + 1;
        }
        else
        {
            count += k - (tmp - k) + 1;
        }
    }

    std::cout << count << std::endl;
    return 0;
}
