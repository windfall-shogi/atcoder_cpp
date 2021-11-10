#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    if (n == 1)
    {
        std::cout << "Hello World" << std::endl;
    }
    else
    {
        int a, b;
        std::cin >> a >> b;
        std::cout << a + b << std::endl;
    }
    return 0;
}
