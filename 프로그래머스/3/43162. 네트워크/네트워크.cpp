#include <string>
#include <vector>
#include <queue>
using namespace std;

void bfs(int node, const vector<vector<int>> &graph , vector<int> &visited)
{    
    queue<int> q;
    q.push(node);
    while(!q.empty())
    {
        int nd = q.front(); q.pop();
        visited[nd] = 1;
        for (int nxt : graph[nd])
        {
            if(visited[nxt] != -1)
                continue;
            q.push(nxt);
        }
    }
    return;
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<vector<int>> graph(n);
    vector<int> visited(n, -1);
    for (int i =0; i < n; i++)
    {
        for (int j =0; j < n; j++)
        {
            if (i == j) continue;
            if (computers[i][j])
            {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }            
        }
    }
    for (int i =0; i < n; i++)
    {
        if(visited[i] == -1)
        {
            bfs(i, graph, visited);
            answer++;
        }
    }
    
    return answer;
}