#include <iostream>
#include <string>
#include <unordered_map>

int main()
{
    std::string s;
    std::cin >> s;
    std::unordered_map<char, int> map;
    for (const auto c : s)
    {
        ++map[c];
    }
    bool ok = map.size() == 2;
    for (const auto &e : map)
    {
        if (e.second != 2)
        {
            ok = false;
            break;
        }
    }

    std::cout << (ok ? "Yes" : "No") << std::endl;
    return 0;
}
