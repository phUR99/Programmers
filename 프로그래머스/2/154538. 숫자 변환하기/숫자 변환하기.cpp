#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dist[1000005];

int solution(int x, int y, int n) {
    int answer = 0;
    queue<int> q;
    fill(dist, dist + 1000005, -1);
    dist[x] = 0;
    q.push(x);
    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        for (int i = 0; i < 3; i++)
        {
            int nxt;
            if (i == 0)
                nxt = cur + n;
            else if (i == 1)
                nxt = cur * 2;
            else 
                nxt = cur * 3;
            if(nxt > 1000000) continue;
            if(dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        } 
    }
    answer = dist[y];
    return answer;
}