#include <iostream>
#include <vector>
#include <utility>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }

    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] == i + 1)
        {
            std::swap(arr[i], arr[i + 1]);
            ++count;
        }
        else if (i == n - 1 && arr[i] == i + 1)
        {
            std::swap(arr[i], arr[i - 1]);
            ++count;
        }
    }

    std::cout << count << std::endl;
    return 0;
}
