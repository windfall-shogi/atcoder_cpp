#include <iostream>
#include <vector>
#include <algorithm>

int solve(std::vector<int>::iterator first, std::vector<int>::iterator last)
{
    if (first == last)
    {
        return 0;
    }

    const int n = *std::min_element(first, last);
    int ans = n;
    std::for_each(first, last, [n](int &h)
                  { h -= n; });

    std::vector<int>::iterator it1 = first;
    while (true)
    {
        for (; it1 != last; ++it1)
        {
            if (*it1 != 0)
            {
                break;
            }
        }
        if (it1 == last)
        {
            return ans;
        }
        std::vector<int>::iterator it2 = it1 + 1;
        for (; it2 != last; ++it2)
        {
            if (*it2 == 0)
            {
                ans += solve(it1, it2);
                it1 = it2;
                break;
            }
        }
        if (it1 == it2)
        {
            continue;
        }

        ans += solve(it1, it2);
        break;
    }
    return ans;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> hs(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> hs[i];
    }

    const int ans = solve(hs.begin(), hs.end());
    std::cout << ans << std::endl;

    return 0;
}
