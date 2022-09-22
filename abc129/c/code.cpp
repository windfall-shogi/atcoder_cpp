#include <iostream>
#include <vector>
#include <unordered_set>

int main()
{
    constexpr int64_t MOD = 1000000007;
    int n, m;
    std::cin >> n >> m;
    std::unordered_set<int> as(m);
    for (int i = 0; i < m; ++i)
    {
        int a;
        std::cin >> a;
        as.emplace(a);
    }

    if (n == 1)
    {
        std::cout << 1 << std::endl;
        return 0;
    }

    int64_t p = 1, q = as.count(1) ? 0 : 1;
    int64_t ans;
    for (int i = 2; i <= n; ++i)
    {
        int64_t new_p = as.count(i - 1) ? 0 : q;
        int64_t new_q = as.count(i) ? 0 : (p + q) % MOD;

        ans = new_q;
        q = new_q;
        p = new_p;
    }

    std::cout << ans << std::endl;
    return 0;
}
