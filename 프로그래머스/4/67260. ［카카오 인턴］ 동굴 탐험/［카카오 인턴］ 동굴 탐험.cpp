#include <string>
#include <vector>
#include <set>
#include <queue>
#include <string.h>
using namespace std;
int child[200005];
int parent[200005];
int visit[200005];
vector<int> adj[200005];
int sz;

int bfs(int x)
{
    int ret = 0;
    set<int> s;
    queue<int> q;
    q.push(x);
    int xp = parent[x];
    if(xp != -1) return 0;
    visit[x] = 1;
    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        for (auto nxt : adj[cur])
        {
            if(visit[nxt]) continue;
            int par = parent[nxt];            
            if(par == -1 || (par != -1 && visit[par]))
            {
                visit[nxt] = 1;
                q.push(nxt);
            }
            else
            {
                s.insert(nxt);    
            }
            int chl = child[nxt];
            if(chl == -1 || (chl!= -1 && s.count(chl) == 0)) continue;
            s.erase(chl);
            q.push(chl);
            visit[chl] = 1;                            
        }
    }
    for (int i = 0; i < sz; i++) ret += visit[i];
    return (ret == sz);
}


bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    bool answer = true;
    sz = n;
    memset(parent, -1, sizeof(parent));
    memset(child, -1, sizeof(child));
    for (auto p : path)
    {
        int a = p[0];
        int b = p[1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (auto p : order)
    {
        int a = p[0];
        int b = p[1];
        parent[b] = a;
        child[a] = b;
    }
    answer = (bool)bfs(0);
    return answer;
}