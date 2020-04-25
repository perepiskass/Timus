#include <iostream>
#include <algorithm>
#include <map>

int main()
{
    int teacher_size = 0;
    std::cin >> teacher_size;
    
    std::map<int,int> teacher_list;

    int str;

    for(int i = 0; i < teacher_size; ++i)
    {   
        std::cin >> str;
        teacher_list[str] = 0;
    }

    int size_stydent = 0;
    std::cin >> size_stydent;
    
    for(int i = 0; i < size_stydent; ++i)
    {   
        std::cin >> str;
        auto it = teacher_list.find(str);
        if(it!=teacher_list.end()) it->second++;
    }

    int sum = 0;

    for (auto& i : teacher_list)
    {
        sum += i.second;
    }
    std::cout << sum;

    return 0;
}