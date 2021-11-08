#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

int main()
{
    std::string s, t;
    std::cin >> s >> t;

    std::vector<std::unordered_set<char>> sets(26);
    for (int i = 0; i < s.size(); ++i)
    {
        sets[s[i] - 'a'].emplace(t[i]);
    }

    bool ok = true;
    for (const auto &e : sets)
    {
        if (e.size() >= 2)
        {
            ok = false;
            break;
        }
    }
    if (ok)
    {
        // 問題を勘違いしていたので、要素の重複がないかを追加で調べる
        // union findで調べればシンプルだった
        std::unordered_set<char> set2;
        int n = 0;
        for (const auto &e : sets)
        {
            if (e.size() == 1)
            {
                for (const auto c : e)
                {
                    set2.emplace(c);
                    ++n;
                }
            }
        }

        if (set2.size() != n)
        {
            ok = false;
        }
    }

    std::cout << (ok ? "Yes" : "No") << std::endl;

    return 0;
}
