#include <iostream>
#include <vector>

int main()
{
    int64_t n, k;
    std::cin >> n >> k;
    std::vector<int64_t> as(n);
    for (int64_t i = 0; i < n; ++i)
    {
        std::cin >> as[i];
    }

    int64_t ans = 0;
    int64_t sum = 0;
    int64_t r = 0;
    for (int64_t l = 0; l < n; ++l)
    {
        if (r < l)
        {
            r = l;
        }
        while (r < n && sum + as[r] < k)
        {
            sum += as[r];
            ++r;
        }
        if (r < n && sum + as[r] >= k)
        {
            ans += n - r;
        }
        else
        {
            break;
        }

        if (l != r)
        {
            sum -= as[l];
        }
    }
    std::cout << ans << std::endl;

    return 0;
}
