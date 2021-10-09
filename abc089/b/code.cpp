#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    bool flag = false;
    for (int i = 0; i < n; ++i)
    {
        char c;
        std::cin >> c;
        if (c == 'Y')
        {
            flag = true;
        }
    }

    std::cout << (flag ? "Four" : "Three") << std::endl;
    return 0;
}
