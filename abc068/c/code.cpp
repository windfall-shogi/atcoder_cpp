#include <iostream>
#include <vector>
#include <unordered_set>

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::unordered_set<int>> arr(n);
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        --a;
        --b;
        arr[a].emplace(b);
        arr[b].emplace(a);
    }

    bool result = false;
    for (const auto a : arr[0])
    {
        const auto it = arr[a].find(n - 1);
        if (it != arr[a].end())
        {
            result = true;
            break;
        }
    }

    if (result)
    {
        std::cout << "POSSIBLE" << std::endl;
    }
    else
    {
        std::cout << "IMPOSSIBLE" << std::endl;
    }
    return 0;
}
