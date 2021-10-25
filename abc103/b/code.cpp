#include <iostream>
#include <string>

int main()
{
    std::string s, t;
    std::cin >> s >> t;

    bool ans = false;
    for (int i = 0; i < s.size(); ++i)
    {
        bool ok = true;
        for (int j = 0; j < s.size(); ++j)
        {
            if (s[j] != t[(i + j) % s.size()])
            {
                ok = false;
                break;
            }
        }

        if (ok)
        {
            ans = true;
            break;
        }
    }

    std::cout << (ans ? "Yes" : "No") << std::endl;

    return 0;
}
