#include <iostream>
#include <vector>
#include <unordered_set>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int64_t> ss(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> ss[i];
    }

    int64_t ans = 0;
    for (int c = 1; c < n - 1; ++c)
    {
        int64_t score = 0;
        std::unordered_set<int> set;
        for (int k = 0; k * c < n; ++k)
        {
            const int a = n - 1 - k * c;
            const int b = a - c;
            if (a <= 0 || b <= 0)
            {
                break;
            }

            set.emplace(k * c);
            if (set.count(a) > 0)
            {
                break;
            }

            score += ss[k * c];
            score += ss[a];

            ans = std::max(ans, score);
        }
    }

    std::cout << ans << std::endl;
    return 0;
}
