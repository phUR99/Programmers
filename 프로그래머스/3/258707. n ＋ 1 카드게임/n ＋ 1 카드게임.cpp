#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;
int p[1005];
int v[1005];
int solution(int coin, vector<int> cards) {
    int answer = 1;
    int n = cards.size();
    int st = n / 3;
    int ed = n / 3;
    int cnt = 0;
    multiset<int> notuse;
    for (int i = 0; i < ed; i++)
    {
        int x = cards[i];
        v[x] = 1;
        if(v[n + 1 -x])
        {
            notuse.insert(0);
        }    
            
    }
    ed += 2;        
    while (st < n)
    {

        v[cards[st]] = 1;
        p[cards[st]] = 1;
        if(v[n+1-cards[st]])
        {
            if(p[n+1-cards[st]]) notuse.insert(2);
            else notuse.insert(1);
        }    

        st++;
        if(st == ed)
        {
            if(notuse.empty()) break;            
            int m = *notuse.begin();
            if(m > coin) break;
            coin -= m;
            notuse.erase(notuse.find(m));
            ed += 2;
            answer++;
        }

    }    
    return answer;
}