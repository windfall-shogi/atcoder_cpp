#include <iostream>
#include <ios>
#include <iomanip>

int main()
{
    int N;
    std::cin >> N;
    if (N >= 42)
    {
        ++N;
    }
    std::cout << "AGC" << std::setfill('0') << std::right << std::setw(3) << N << std::endl;
    return 0;
}
