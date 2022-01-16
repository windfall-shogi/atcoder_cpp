#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

bool solve(const int a, const int b, const int c, const std::vector<int> &ls,
           const int x, const int y, const int z, const int index, const int current_cost, int &min_cost)
{
    if (index == ls.size())
    {
        if (x == 0 || y == 0 || z == 0)
        {
            return false;
        }

        const int cost = current_cost + std::abs(a - x) + std::abs(b - y) + std::abs(c - z);
        if (cost < min_cost)
        {
            min_cost = cost;
        }
        return true;
    }
    if (current_cost + std::max(x - a, 0) + std::max(y - b, 0) + std::max(z - c, 0) >= min_cost)
    {
        return false;
    }

    // この探索で有効な結果が得られたかどうか
    bool result = false;
    for (int i = 0; i < 4; ++i)
    {
        bool flag;
        switch (i)
        {
        case 0:
            flag = solve(a, b, c, ls, x + ls[index], y, z, index + 1, current_cost + 10, min_cost);
            break;
        case 1:
            flag = solve(a, b, c, ls, x, y + ls[index], z, index + 1, current_cost + 10, min_cost);
            break;
        case 2:
            flag = solve(a, b, c, ls, x, y, z + ls[index], index + 1, current_cost + 10, min_cost);
            break;
        default:
            flag = solve(a, b, c, ls, x, y, z, index + 1, current_cost, min_cost);
            break;
        }
        if (flag)
        {
            result = true;
        }
    }
    return result;
}

int main()
{
    int n, a, b, c;
    std::cin >> n >> a >> b >> c;
    std::vector<int> ls(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> ls[i];
    }

    int ans = std::numeric_limits<int>::max();
    solve(a, b, c, ls, 0, 0, 0, 0, -30, ans);
    std::cout << ans << std::endl;
    return 0;
}
