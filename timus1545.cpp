#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
    int size_dictionary = 0;
    std::cin >> size_dictionary;
    
    std::vector<std::string> dictionary;
    dictionary.reserve(size_dictionary);

    std::string str;
    std::getline(std::cin,str);

    for(int i = 0; i < size_dictionary; ++i)
    {   
        std::getline(std::cin,str);
        dictionary.emplace_back(str);
    }

    char ch;
    std::cin >> ch;

    std::for_each(std::begin(dictionary),std::end(dictionary),[&ch](const std::string& word){
        if(word[0] == ch) std::cout << word << std::endl;
    });

    return 0;
}