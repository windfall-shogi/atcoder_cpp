#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int main()
{
    int n, q;
    std::cin >> n >> q;
    std::vector<int64_t> ss(n), ts(n), xs(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> ss[i] >> ts[i] >> xs[i];
    }
    std::vector<int64_t> ds(q);
    for (int i = 0; i < q; ++i)
    {
        std::cin >> ds[i];
    }

    std::vector<int64_t> ans(q, -1);
    for (int i = 0; i < n; ++i)
    {
        int64_t s = ss[i], t = ts[i], x = xs[i];
        s -= x;
        t -= x;

        const auto it1 = std::lower_bound(ds.begin(), ds.end(), s);
        const auto it2 = std::lower_bound(it1, ds.end(), t);

        const auto j = std::distance(ds.begin(), it1);
        const auto k = std::distance(ds.begin(), it2);
        for (auto m = j; m < k; ++m)
        {
            if (ans[m] == -1)
            {
                ans[m] = x;
            }
            else if (x < ans[m])
            {
                ans[m] = x;
            }
        }
    }

    for (const auto v : ans)
    {
        std::cout << v << std::endl;
    }
    return 0;
}
