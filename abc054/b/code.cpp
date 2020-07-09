#include <iostream>
#include <vector>
#include <string>

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> a(n), b(m);
    for (int i = 0; i < n; ++i)
    {
        std::string tmp;
        std::cin >> tmp;
        a[i] = std::move(tmp);
    }
    for (int i = 0; i < m; ++i)
    {
        std::string tmp;
        std::cin >> tmp;
        b[i] = std::move(tmp);
    }

    bool exists = false;
    for (int y = 0; y <= n - m; ++y)
    {
        for (int x = 0; x <= n - m; ++x)
        {
            if (a[y][x] != b[0][0])
            {
                continue;
            }

            bool match = true;
            for (int i = 0; i < m; ++i)
            {
                for (int j = 0; j < m; ++j)
                {
                    if (a[y + i][x + j] != b[i][j])
                    {
                        match = false;
                        break;
                    }
                }
                if (!match)
                {
                    break;
                }
            }
            if (match)
            {
                exists = true;
                break;
            }
        }
        if (exists)
        {
            break;
        }
    }

    if (exists)
    {
        std::cout << "Yes";
    }
    else
    {
        std::cout << "No";
    }
    std::cout << std::endl;

    return 0;
}
