#include <iostream>
#include <vector>

bool Check(const int count1, const int count2, const int count4)
{
    if (count1 >= count4 + 2)
    {
        return false;
    }
    else if (count1 >= count4 + 1)
    {
        return count2 == 0;
    }
    else
    {
        return true;
    }
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    int count4 = 0, count2 = 0, count1 = 0;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
        if (arr[i] % 4 == 0)
        {
            ++count4;
        }
        else if (arr[i] % 2 == 0)
        {
            ++count2;
        }
        else
        {
            ++count1;
        }
    }

    const bool result = Check(count1, count2, count4);
    if (result)
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }
    return 0;
}
