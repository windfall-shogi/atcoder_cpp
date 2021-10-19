#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;

    constexpr int INF = 100000 + 1;
    std::vector<int> memo(n + 1, INF);
    memo[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        int k = memo[i - 1] + 1;
        for (int v : {6, 9})
        {
            int tmp = v;
            while (tmp <= i)
            {
                k = std::min(k, memo[i - tmp] + 1);
                tmp *= v;
            }
        }
        memo[i] = k;
    }
    std::cout << memo[n] << std::endl;

    return 0;
}
