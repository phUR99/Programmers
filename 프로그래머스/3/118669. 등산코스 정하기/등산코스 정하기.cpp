#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#define INF 987654321
using namespace std;

int dist[50005];
int gate[50005];
int summ[50005];
vector<pair<int, int>> adj[50005];

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    priority_queue<pair<int, int>> pq;
    fill(dist, dist + n + 1, INF);
    for (auto p : paths)
    {
        int a = p[0];
        int b = p[1];
        int w = p[2];
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    for (auto g : gates)
    {
        gate[g] = 1;        
        pq.push({0, g});
        dist[g] = 0;
    }
    
    for (auto s : summits)
        summ[s] = 1;
    
    while (!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        int cw = -cur.first;
        int ca = cur.second;
        for (auto nxt : adj[ca])
        {
            int nb = nxt.first;
            int nw = nxt.second;
            // cout << nb << ' ' << nw << '\n';
            if (max(cw, nw) < dist[nb])
            {
                dist[nb] = max(cw, nw);
                if(summ[nb] == 1) continue;
                pq.push({-dist[nb], nb});
            }
        }
    }
    answer = {0, INF};
    for (int i = 0; i <= n; i ++)
    {
        if(summ[i] && (dist[i] < answer[1]))
        {
            answer[0] = i;
            answer[1] = dist[i];
        }
    }
    
    return answer;
}