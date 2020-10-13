#include <iostream>
#include <string>

int main()
{
    std::string s;
    std::cin >> s;
    const size_t n = s.size();

    for (int i = 2; i < n; i += 2)
    {
        const int c = (n - i) / 2;
        bool ok = true;
        for (int j = 0; j < c; ++j)
        {
            if (s[j] != s[c + j])
            {
                ok = false;
                break;
            }
        }

        if (ok)
        {
            std::cout << n - i << std::endl;
            break;
        }
    }

    return 0;
}
