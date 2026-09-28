#include <string>
#include <vector>
#include <string.h>
#include <iostream>
#include <queue>
using namespace std;


vector<pair<int, int>> adj[105];
int M = 0;
int kk;
int nn;

void dfs(int p, vector<int> visited)
{    

    int ret = 0;
    for (int i = 1; i <= nn; i ++) ret += (visited[i]);
    M = max(ret, M);
    if(p == kk)
    {
        return;
    }    
    for (int i = 1; i <= 3; i++)
    {
        vector<int> nv = visited;
        queue<int> q;
        for (int j = 1; j<= nn; j++)
        {
            if(visited[j]) q.push(j);
        }
        while (!q.empty())
        {
            int cur = q.front(); q.pop();
            for (auto nxt : adj[cur])
            {
                int ne = nxt.first;
                int nt = nxt.second;
                if(nv[ne]) continue;
                if(i != nt) continue;
                nv[ne] = 1;
                q.push(ne);
            }            
        }
        dfs(p + 1, nv);
    }        
}
int solution(int n, int infection, vector<vector<int>> edges, int k) {
    int answer = 0;
    kk = k;
    nn = n;    
    for(auto e : edges) {
        adj[e[0]].push_back({e[1], e[2]});    
        adj[e[1]].push_back({e[0], e[2]});    
    }
    vector<int> visit(n + 1, 0);
    visit[infection] = 1;
    dfs(0, visit);
    answer = M;
    return answer;
}