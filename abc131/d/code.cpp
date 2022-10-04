#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::pair<int64_t, int64_t>> tasks(n);
    for (int i = 0; i < n; ++i)
    {
        int64_t a, b;
        std::cin >> a >> b;
        tasks[i] = std::make_pair(b, a);
    }
    std::sort(tasks.begin(), tasks.end());

    int64_t t = 0;
    bool ok = true;
    for (const auto &e : tasks)
    {
        t += e.second;
        if (e.first < t)
        {
            ok = false;
            break;
        }
    }

    std::cout << (ok ? "Yes" : "No") << std::endl;
    return 0;
}
