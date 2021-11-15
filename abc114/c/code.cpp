#include <iostream>
#include <unordered_set>

bool check(const int x)
{
    if (x < 357)
    {
        return false;
    }

    int num = x;
    bool ok7 = false, ok5 = false, ok3 = false;
    while (num != 0)
    {
        const int tmp = num % 10;
        switch (tmp)
        {
        case 3:
            ok3 = true;
            break;
        case 5:
            ok5 = true;
            break;
        case 7:
            ok7 = true;
            break;
        default:
            return false;
        }

        num /= 10;
    }
    return ok7 && ok5 && ok3;
}

int main()
{
    int n;
    std::cin >> n;

    std::unordered_set<int> current, previous{3, 5, 7};
    std::unordered_set<int> table;
    while (!previous.empty())
    {
        for (const int k : {3, 5, 7})
        {
            for (const int v : previous)
            {
                int64_t x = static_cast<int64_t>(v) * 10 + k;
                if (x <= n)
                {
                    current.emplace(x);
                    table.emplace(x);
                }
            }
        }

        current.swap(previous);
        current.clear();
    }

    int ans = 0;
    for (const int x : table)
    {
        if (check(x))
        {
            ++ans;
        }
    }
    std::cout << ans << std::endl;

    return 0;
}
