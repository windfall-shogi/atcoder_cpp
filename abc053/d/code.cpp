#include <iostream>
#include <vector>
#include <unordered_map>

int main()
{
    int n;
    std::cin >> n;
    std::unordered_map<int, int> map;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        ++map[tmp];
    }

    int count1 = 0, count2 = 0;
    for (const auto &e : map)
    {
        // 3枚以上の場合は2枚ずつ減らせるので
        // 結局のところでカードの枚数は1枚か2枚
        if (e.second % 2 == 1)
        {
            ++count1;
        }
        else
        {
            ++count2;
        }
    }

    if (count2 == 0)
    {
        // 重複がない
        std::cout << count1 << std::endl;
        return 0;
    }

    // 重複しているものからそれぞれ異なる数字を取り出すと
    // 重複していない2枚とそのまま重複している1枚にできる
    if (count2 >= 3)
    {
        const int tmp = (count2 - 1) / 2 * 2;

        count1 += tmp;
        count2 -= tmp;
    }
    // 重複しているのは1種類か2種類
    // 1種類の場合：
    //  重複している2枚と重複していない1枚を取り出す
    //  1枚返ってくるのでcount1の値は変化しない
    // 2種類の場合：
    //  重複しているカードの値をa, a, b, bとする
    //  a, a, bを取り出す
    //  返ってくるのはa
    //  残ったのはa, bでcount1の値は2増える
    if (count2 == 1)
    {
        std::cout << count1;
    }
    else
    {
        std::cout << count1 + 2;
    }
    std::cout << std::endl;
    return 0;
}
