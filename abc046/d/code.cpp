#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::string str;
    std::cin >> str;
    int count = 0;
    for(const char c:str){
        if(c=='p'){
            ++count;
        }
    }
    
    std::cout << str.size() / 2 - count << std::endl;

    return 0;
}
