#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

bool search(const std::vector<int> &count, int i, const int goal)
{
    std::unordered_set<int> current, next;
    current.insert(0);
    for (; i < count.size(); i += 2)
    {
        if (i == 0)
        {
            next.insert(count[i]);
        }
        else
        {
            for (const int n : current)
            {
                next.insert(n + count[i]);
                next.insert(n - count[i]);
            }
        }
        next.swap(current);
        next.clear();
    }

    const auto it = current.find(goal);
    return it != current.end();
}

int main()
{
    std::string s;
    std::cin >> s;
    int x, y;
    std::cin >> x >> y;

    std::vector<int> count;
    int n = 0;
    for (const auto c : s)
    {
        if (c == 'T')
        {
            count.emplace_back(n);
            n = 0;
        }
        else
        {
            ++n;
        }
    }
    if (n != 0)
    {
        count.emplace_back(n);
    }

    const bool result = search(count, 0, x) && search(count, 1, y);
    std::cout << (result ? "Yes" : "No") << std::endl;
    return 0;
}
