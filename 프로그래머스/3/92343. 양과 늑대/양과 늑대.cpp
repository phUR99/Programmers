#include <string>
#include <vector>
#include <string.h>
#include <iostream>
using namespace std;

int l[20];
int r[20];
int M = 0;
int visit[1<<17+1];
void dfs(int cur, int state, vector<int> &info)
{
    int s = 0;
    int w = 0;
    for(int i =0; i < info.size(); i++)
    {
        if(state & (1 << i))
        {
            if(info[i]) w++;
            else s++;
        }
    }
    if(w >= s) return;
    M = max(M, s);
    // cout << cur << ' ';
    for(int i =0; i < info.size(); i++)
    {
        int pos = state & (1 << i);
        if(pos)
        {            
            if(l[i] != -1)
            {
                int nxt = state | (1 << l[i]);
                if(visit[nxt] == -1) 
                {
                    visit[nxt] = 1;
                    dfs(l[i], nxt, info);
                }
                    
            }
            if(r[i] != -1)
            {
                int nxt = state | (1 << r[i]);
                if(visit[nxt] == -1) 
                {
                    visit[nxt] = 1;
                    dfs(r[i], nxt, info);
    
                }
                    
            }    
            
        }
    }
    return;
}
int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    memset(l, -1, sizeof(l));
    memset(r, -1, sizeof(r));
    memset(visit, -1, sizeof(visit));
    for (auto e : edges)
    {
        if(l[e[0]] == -1) l[e[0]] = e[1];
        else r[e[0]] = e[1];
    }
    int init = 1 << 0;
    visit[init] = 1;
    dfs(0, init, info);
    answer = M;
    return answer;
}