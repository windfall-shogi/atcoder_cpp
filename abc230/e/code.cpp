#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int64_t N;
    std::cin >> N;

    int64_t k;
    for (int64_t i = 1; i <= N; ++i)
    {
        if (i * i <= N)
        {
            k = i;
        }
        else
        {
            break;
        }
    }

    int64_t ans = 0;
    for (int64_t i = 1; i <= k; ++i)
    {
        ans += N / i;
    }
    for (int64_t i = 1; i <= N / (k + 1); ++i)
    {
        ans += i * (N / i - N / (i + 1));
    }

    std::cout << ans << std::endl;

    return 0;
}
