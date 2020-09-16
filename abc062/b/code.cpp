#include <iostream>
#include <vector>
#include <string>

int main()
{
    int h, w;
    std::cin >> h >> w;
    std::vector<std::string> img(h);
    for (int i = 0; i < h; ++i)
    {
        std::cin >> img[i];
    }

    for (int i = 0; i < w + 2; ++i)
    {
        std::cout << '#';
    }
    std::cout << std::endl;
    for (int i = 0; i < h; ++i)
    {
        std::cout << '#' << img[i] << '#' << std::endl;
    }
    for (int i = 0; i < w + 2; ++i)
    {
        std::cout << '#';
    }
    std::cout << std::endl;

    return 0;
}
