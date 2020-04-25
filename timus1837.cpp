#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <list>
#include <utility>

constexpr int team_size = 3; 
using names = std::list<std::pair<std::string,int>>;

bool find( std::map<std::string, int>& result,std::map<int,names>& teams,int N,bool End)
{
        End = true;
        for(auto& i : teams)
        {
            for(auto it = i.second.begin(); it !=i.second.end(); )
            {
                if(result.find((*it).first) != result.end())
                {
                    it = i.second.erase(it);
                }
                else ++it;
            }
            if(i.second.size() < 3)
                {
                    for(auto& list : i.second)
                    {
                        list.second = N+1;
                    }
                }
        }

        for(auto it =teams.begin(); it !=teams.end(); )
        {
            if ((*it).second.size() < 3)
            {
                for(auto& list : (*it).second)
                {
                    result[list.first] = list.second;
                }

                it = teams.erase(it);
                End = false;
            }
            else ++it;
        }
    
    if(End) return false;
    else return find(result,teams,N+1,End);
}
 
int main()
{
    
    bool Isenbaev = false;
  int n;
  std::cin >> n;

  std::map<int,names> teams;
    std::map<std::string, int> result;

  std::string buff;
  std::getline(std::cin, buff);

  for(int i = 0; i < n; ++i) 
  {
    std::string nameS;
    for(int j = 0; j < team_size; ++j) 
    {
      char delim = (j == (team_size - 1)) ? '\n' : ' ';
      std::getline(std::cin, nameS, delim);
      if (nameS != "Isenbaev") teams[i].push_back(std::make_pair(nameS,0));
      else Isenbaev = true;
    }
        if (teams[i].size() == 2) 
            {
                result[teams[i].front().first] = 1;
                result[teams[i].back().first] = 1;

                teams.erase(i);
            }
  }

    find(result,teams,1,false);
    if(Isenbaev) result["Isenbaev"] = 0;

    for(auto&it : teams)
    {
        for(auto&i : it.second)
        {
            result[i.first] = -1;
        }
    }

    for(auto i : result)
    {
        if (i.second >=0) std::cout << i.first << ' ' << i.second << std::endl;
        else std::cout << i.first << ' ' << "undefined" << std::endl;
    }
 
    return 0;
}