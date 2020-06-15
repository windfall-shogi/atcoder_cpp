#include <iostream>
#include <vector>
#include <string>

int main()
{
    int h, w;
    std::cin >> h >> w;
    std::vector<std::string> buffer;
    buffer.reserve(h);
    for (int i = 0; i < h; ++i)
    {
        std::string tmp;
        std::cin >> tmp;
        buffer.emplace_back(std::move(tmp));
    }

    for (int i = 0; i < 2 * h; ++i)
    {
        std::cout << buffer[i / 2] << std::endl;
    }

    return 0;
}
