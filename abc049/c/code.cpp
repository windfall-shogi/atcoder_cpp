#include <iostream>
#include <string>
#include <regex>

int main()
{
    std::string s;
    std::cin >> s;

    std::smatch smatch;
    const std::regex r("(dream|dreamer|erase|eraser)$");
    while (true)
    {
        if (std::regex_search(s, smatch, r))
        {
            for (auto it = smatch[0].first; it != smatch[0].second; ++it)
            {
                s.pop_back();
            }
            if (s.empty())
            {
                std::cout << "YES" << std::endl;
                break;
            }
        }
        else
        {
            std::cout << "NO" << std::endl;
            break;
        }
    }
    return 0;
}
