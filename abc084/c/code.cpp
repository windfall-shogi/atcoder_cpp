#include <iostream>
#include <vector>

int get_time(const int i, const int t, const std::vector<int> &ss,
             const std::vector<int> &fs)
{
    if (t < ss[i])
    {
        return ss[i];
    }
    else
    {
        return (t + fs[i] - 1) / fs[i] * fs[i];
    }
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> cs(n), ss(n), fs(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> cs[i] >> ss[i] >> fs[i];
    }

    for (int i = 0; i < n; ++i)
    {
        int t = 0;
        for (int j = i; j < n - 1; ++j)
        {
            t = get_time(j, t, ss, fs) + cs[j];
        }
        std::cout << t << std::endl;
    }

    return 0;
}
