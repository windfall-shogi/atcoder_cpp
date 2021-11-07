#include <iostream>
#include <string>
#include <unordered_set>

int main()
{
    int n;
    std::cin >> n;
    std::string previous;

    std::unordered_set<std::string> set;
    bool ok = true;
    for (int i = 0; i < n; ++i)
    {
        if (i == 0)
        {
            std::cin >> previous;
            set.emplace(previous);
        }
        else
        {
            std::string s;
            std::cin >> s;
            if (previous.back() != s.front())
            {
                ok = false;
            }

            set.emplace(s);
            previous = std::move(s);
        }
    }

    if (set.size() != n)
    {
        ok = false;
    }

    std::cout << (ok ? "Yes" : "No") << std::endl;

    return 0;
}
