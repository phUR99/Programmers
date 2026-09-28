#include <string>
#include <vector>
#include <string.h>
#include <iostream>
#include <queue>
using namespace std;


vector<pair<int, int>> adj[105];
int visited[105];

int check(int m)
{
    int pre = -1 ;
    while (m)
    {
        int re = m % 3;
        if(re == pre) return 0;
        m /= 3;
        pre = re;
    }
    return 1;
}

int solution(int n, int infection, vector<vector<int>> edges, int k) {
    int answer = 0;    
    for(auto e : edges) {
        adj[e[0]].push_back({e[1], e[2]});    
        adj[e[1]].push_back({e[0], e[2]});    
    }
    
    int M = 1;
    for (int i = 0; i < k; i++) M *= 3;
    for (int i = 0; i < M; i++)
    {
        int pre = -1;
        if (!check(i)) continue;
        memset(visited, -1, sizeof(visited));
        int st = i;
        int kk = k;
        queue<int> q;        
        visited[infection] = 1;
        while(kk--)
        {            
            int state = st % 3;
            st /= 3;
            for (int j = 1; j <= n; j++) if(visited[j] == 1) q.push(j);
            while(!q.empty())
            {
                int c = q.front(); q.pop();
                for (auto nx : adj[c])
                {
                    if(visited[nx.first] == 1 || nx.second - 1 != state) continue;
                    visited[nx.first] = 1;
                    q.push(nx.first);
                }
                
            }                        
        }    
        int ret = 0;
        for (int j = 1; j <= n; j++) if(visited[j] == 1) ret++;
        answer = max(ret, answer);
    }
    
    return answer;
}