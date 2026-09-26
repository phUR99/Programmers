#include <string>
#include <vector>
#include <queue>
using namespace std;
#define INF 987654321
vector<int> dist_s(205, INF), dist_a(205, INF), dist_b(205, INF);
vector<pair<int, int>> adj[205];

void dijkstra(int st, vector<int> &dist)
{
    priority_queue<pair<int, int>> pq;
    dist[st] = 0;
    pq.push({-0, st});
    while(!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        int cw = -cur.first;
        int ce = cur.second;
        for (auto nxt : adj[ce])
        {
            int nw = cw + nxt.second;
            int ne = nxt.first;
            if(dist[ne] > nw)
            {
                dist[ne] = nw;
                pq.push({-nw, ne});
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    
    for (auto f : fares)
    {
        int s = f[0];
        int e = f[1];
        int w = f[2];
        adj[s].push_back({e, w});
        adj[e].push_back({s, w});
    }
    dijkstra(s, dist_s);
    dijkstra(a, dist_a);
    dijkstra(b, dist_b);
    answer = INF;
    for (int i = 1; i <= n; i++)
    {
        if(dist_s[i] == INF || dist_a[i] == INF || dist_b[i] == INF) continue;
        answer = min(answer, dist_s[i] + dist_a[i] + dist_b[i]);
    }
    
    return answer;
}