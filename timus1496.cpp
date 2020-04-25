#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <utility>

int main ()
{
    int size = 0;
    std::cin >> size;

    std::map<std::string,int> dictionary;

    std::string str;
    std::getline(std::cin,str);

    for(int i = 0; i < size; ++i)
    {   
        std::getline(std::cin,str);
        ++dictionary[str];
    }

    std::for_each(std::begin(dictionary),std::end(dictionary),[](const std::pair<const std::string,int>& word){
        if(word.second > 1) std::cout << word.first << std::endl;
    });

}