#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2, 0);
    int t = 0;
    set<string> s;
    for (auto g : gems)
    {
        if(!s.count(g)) s.insert(g);
    }
    t = s.size();
    int p = 0;
    int l = 0;
    int d = 987654321;
    multiset<string> ms;
    for (int r = 0; r < gems.size(); r++)
    {
        if(ms.count(gems[r]) == 0)
        {
            p++;
        }
        ms.insert(gems[r]);
        while (l <= r)
        {
            if(ms.count(gems[l]) >= 2)
            {
                ms.erase(ms.find(gems[l++]));                
            }
            else
                break;
        }
        if(p == t && d > r - l)
        {
            d = r - l;
            answer = {l + 1 , r + 1};            
        }
    }
    return answer;
}