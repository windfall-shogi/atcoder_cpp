#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
        // インデックスを調整
        --arr[i];
    }

    std::vector<bool> pushed(n, false);
    int index = 0;
    int count = 0;
    while (true)
    {
        if (pushed[index])
        {
            count = -1;
            break;
        }
        pushed[index] = true;
        index = arr[index];
        ++count;
        if (index == 1)
        {
            break;
        }
    }

    std::cout << count << std::endl;
    return 0;
}
