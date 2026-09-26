#include <string>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;
vector<int> adj[20005];
int dist[20005];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    for (auto e : edge)
    {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    q.push(1);
    dist[1] = 0;
    while (!q.empty())
    {
        int c = q.front(); q.pop();
        for (int nxt : adj[c])
        {
            if(dist[nxt] == -1)
            {
                q.push(nxt);
                dist[nxt] = dist[c] + 1;
            }
        }
    }
    int M = 0;
    for (int i = 1; i <= n; i ++)  M = max(M, dist[i]);
    for (int i = 1; i <= n; i ++)  answer += (M == dist[i]);
    
    
    return answer;
}