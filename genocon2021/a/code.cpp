#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int main()
{
    int m;
    std::cin >> m;
    std::vector<std::string> ss(m);
    for (int i = 0; i < m; ++i)
    {
        std::cin >> ss[i];
    }

    const std::unordered_map<char, char> complements{{'A', 'T'}, {'T', 'A'}, {'C', 'G'}, {'G', 'C'}};

    for (const std::string &s : ss)
    {
        for (std::string::const_reverse_iterator it = s.rbegin(); it != s.rend(); ++it)
        {
            std::cout << complements.at(*it);
        }
        std::cout << std::endl;
    }

    return 0;
}
