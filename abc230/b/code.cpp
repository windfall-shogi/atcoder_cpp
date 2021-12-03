#include <iostream>
#include <string>

int main()
{
    std::string S;
    std::cin >> S;

    std::string T;
    for (int i = 0; i < 10; ++i)
    {
        T += "oxx";
    }

    bool match = false;
    for (int i = 0; i < 3; ++i)
    {
        const auto tmp = T.substr(i, S.size());
        if (tmp == S)
        {
            match = true;
            break;
        }
    }

    std::cout << (match ? "Yes" : "No") << std::endl;

    return 0;
}
