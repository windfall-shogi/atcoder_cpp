#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    bool flag = false;
    for (int i = 0; i <= n / 7; ++i)
    {
        if ((n - i * 7) % 4 == 0)
        {
            flag = true;
            break;
        }
    }

    std::cout << (flag ? "Yes" : "No") << std::endl;

    return 0;
}
