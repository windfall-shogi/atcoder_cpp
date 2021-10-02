#include <iostream>
#include <string>
#include <array>
#include <set>

int main()
{
    std::string s, t;
    std::cin >> s >> t;

    std::array<int, 26> as = {0}, at = {0};
    std::set<char> ss, st;
    for (const auto &c : s)
    {
        ++as[c - 'a'];
        ss.insert(c);
    }
    for (const auto &c : t)
    {
        ++at[c - 'a'];
        st.insert(c);
    }

    bool flag;
    if (*ss.begin() < *st.rbegin())
    {
        flag = true;
    }
    else if (*ss.begin() == *st.rbegin())
    {
        if (ss.size() == 1)
        {
            flag = as[*ss.begin() - 'a'] < at[*st.rbegin() - 'a'];
        }
        else
        {
            flag = false;
        }
    }

    std::cout << (flag ? "Yes" : "No") << std::endl;
    return 0;
}
