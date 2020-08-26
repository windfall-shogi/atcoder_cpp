#include <iostream>
#include <vector>

int64_t Compute(const std::vector<int> &arr, const bool flag)
{
    int sign = flag ? +1 : -1;
    int64_t sum = 0;
    int64_t count = 0;
    for (size_t i = 0; i < arr.size(); ++i)
    {
        sum += arr[i];
        if (sum == 0)
        {
            ++count;
            sum = sign;
        }
        else if (sum * sign > 0)
        {
            // 条件を満たす
        }
        else
        {
            // 条件を満たさない
            count += abs(sum) + 1;
            sum = sign;
        }
        sign *= -1;
    }

    return count;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        arr[i] = tmp;
    }

    const auto count = std::min(Compute(arr, true), Compute(arr, false));
    std::cout << count << std::endl;

    return 0;
}
