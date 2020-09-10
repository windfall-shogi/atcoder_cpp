#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
using namespace std;

int main()
{
    int64_t n, k;
    cin >> n >> k;

    vector<pair<int, int>> c;
    c.reserve(n);
    for (int64_t i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;

        c.emplace_back(make_pair(a, b));
    }
    sort(c.begin(), c.end());

    for (int64_t i = 0; i < n; ++i)
    {
        const auto &t = c[i];
        if (t.second >= k)
        {
            cout << t.first << endl;
            break;
        }
        else
        {
            k -= t.second;
        }
    }
    return 0;
}
