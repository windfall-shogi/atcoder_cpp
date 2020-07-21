#include <iostream>
#include <vector>
#include <string>

enum Animal
{
    S, // sheep
    W  // wolf
};

bool Solve(const std::string &s, std::vector<Animal> &arr)
{
    for (int i = 1; i < s.size() - 1; ++i)
    {
        if (arr[i] == S)
        {
            if (s[i] == 'o')
            {
                arr[i + 1] = arr[i - 1];
            }
            else
            {
                arr[i + 1] = static_cast<Animal>(1 - arr[i - 1]);
            }
        }
        else
        {
            if (s[i] == 'o')
            {
                arr[i + 1] = static_cast<Animal>(1 - arr[i - 1]);
            }
            else
            {
                arr[i + 1] = arr[i - 1];
            }
        }
    }

    const auto n = s.size();

    if (arr[0] == S)
    {
        if (s[0] == 'o' && arr[n - 1] != arr[1])
        {
            return false;
        }
        else if (s[0] == 'x' && arr[n - 1] == arr[1])
        {
            return false;
        }
    }else{
        if (s[0] == 'o' && arr[n - 1] == arr[1])
        {
            return false;
        }
        else if (s[0] == 'x' && arr[n - 1] != arr[1])
        {
            return false;
        }
    }

    const int i = n - 1;
    if (arr[i] == S)
    {
        if (s[i] == 'o')
        {
            return arr[0] == arr[i - 1];
        }
        else
        {
            return arr[0] != arr[i - 1];
        }
    }
    else
    {
        if (s[i] == 'o')
        {
            return arr[0] != arr[i - 1];
        }
        else
        {
            return arr[0] == arr[i - 1];
        }
    }
}

void Output(std::vector<Animal> &arr)
{
    for (const Animal a : arr)
    {
        if (a == S)
        {
            std::cout << 'S';
        }
        else
        {
            std::cout << 'W';
        }
    }
    std::cout << std::endl;
}

int main()
{
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    std::vector<Animal> arr(n);
    // 先頭がSSを仮定
    arr[0] = arr[1] = S;
    if (Solve(s, arr))
    {
        Output(arr);
        return 0;
    }

    arr[0] = S;
    arr[1] = W;
    if (Solve(s, arr))
    {
        Output(arr);
        return 0;
    }

    arr[0] = W;
    arr[1] = S;
    if (Solve(s, arr))
    {
        Output(arr);
        return 0;
    }

    arr[0] = arr[1] = W;
    if (Solve(s, arr))
    {
        Output(arr);
        return 0;
    }

    std::cout << -1 << std::endl;
    return 0;
}
