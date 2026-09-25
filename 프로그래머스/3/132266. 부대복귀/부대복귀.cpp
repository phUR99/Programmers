#include <string>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

vector<vector<int>> graph;
int dist[100005];

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    memset(dist, -1, sizeof(dist));
    graph.resize(n + 1);
    
    for (auto r : roads)
    {
        int s = r[0];
        int d = r[1];
        graph[s].push_back(d);
        graph[d].push_back(s);
    }
    
    queue<int> q;
    q.push(destination);
    dist[destination] = 0;
    while (!q.empty())
    {
        int c = q.front(); q.pop();
        for (int nxt : graph[c])
        {
            if(dist[nxt] == -1)
            {
                dist[nxt] = dist[c] + 1;
                q.push(nxt);
            }
        }
    }
    for (auto s : sources) answer.push_back(dist[s]);
    return answer;
}