#include <iostream>
#include <vector>

int main()
{
    int h, w;
    std::cin >> h >> w;
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }

    std::vector<int> map;
    map.reserve(h * w);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < arr[i]; ++j)
        {
            map.push_back(i + 1);
        }
    }

    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            if (i % 2 == 0)
            {
                std::cout << map[i * w + j];
            }
            else
            {
                std::cout << map[i * w + w - j - 1];
            }
            if (j < w - 1)
            {
                std::cout << ' ';
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
