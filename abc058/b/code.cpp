#include <iostream>
#include <string>

int main()
{
    std::string o, e;
    std::cin >> o;
    std::cin >> e;
    for (size_t i = 0; i < e.size(); ++i)
    {
        std::cout << o[i] << e[i];
    }
    if (o.size() != e.size())
    {
        std::cout << o.back();
    }
    std::cout << std::endl;
    return 0;
}
