#include <iostream>
#include <string>
#include <array>

enum Name
{
    M,
    A,
    R,
    C,
    H
};

int main()
{
    int n;
    std::cin >> n;
    std::array<int, 5> names = {0};
    for (int i = 0; i < n; ++i)
    {
        std::string tmp;
        std::cin >> tmp;
        switch (tmp[0])
        {
        case 'M':
            ++names[M];
            break;
        case 'A':
            ++names[A];
            break;
        case 'R':
            ++names[R];
            break;
        case 'C':
            ++names[C];
            break;
        case 'H':
            ++names[H];
            break;
        default:
            break;
        }
    }

    int64_t sum = 0;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = i + 1; j < 4; ++j)
        {
            for (int k = j + 1; k < 5; ++k)
            {
                sum += static_cast<int64_t>(names[i]) * names[j] * names[k];
            }
        }
    }

    std::cout << sum << std::endl;
    return 0;
}
