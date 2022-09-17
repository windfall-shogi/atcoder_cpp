#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

struct Data
{
    std::string s;
    int p;
    int i;

    bool operator<(const Data &d) const
    {
        if (s == d.s)
        {
            return p > d.p;
        }
        else
        {
            return s < d.s;
        }
    }
};

int main()
{
    int n;
    std::cin >> n;
    std::vector<Data> ds(n);
    for (int i = 0; i < n; ++i)
    {
        std::string s;
        int p;
        std::cin >> s >> p;
        ds[i] = Data{s, p, i + 1};
    }
    std::sort(ds.begin(), ds.end());

    for (const auto &d : ds)
    {
        std::cout << d.i << std::endl;
    }
    return 0;
}
