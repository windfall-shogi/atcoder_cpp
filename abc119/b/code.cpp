#include <iostream>
#include <string>
#include <iomanip>

int main()
{
    int n;
    std::cin >> n;
    double sum = 0;
    for (int i = 0; i < n; ++i)
    {
        double x;
        std::string u;
        std::cin >> x >> u;
        if (u == "JPY")
        {
            sum += x;
        }
        else
        {
            sum += x * 380000.0;
        }
    }
    std::cout << std::setprecision(15) << sum << std::endl;
    return 0;
}
