#include <iostream>
#include <array>
#include <algorithm>

int main()
{
    int a, b, c; 
    std::cin >> a >> b >> c;
    std::array<int, 3> arr{{a, b, c}};
    std::sort(arr.begin(), arr.end());
    if (arr[0] == 5 && arr[1] == 5 && arr[2] == 7)
    {
        std::cout << "YES";
    }
    else
    {
        std::cout << "NO";
    }
    std::cout << std::endl;

    return 0;
}
