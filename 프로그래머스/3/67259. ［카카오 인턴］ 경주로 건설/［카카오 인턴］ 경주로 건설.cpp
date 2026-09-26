#include <string>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int dist[30][30][4];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int solution(vector<vector<int>> board) {
    int answer = 0;
    int n = board.size();
    memset(dist, -1, sizeof(dist));
    dist[0][0][1] = 0;
    dist[0][0][3] = 0;
    queue<vector<int>> q;
    q.push({0, 0, 1});
    q.push({0, 0, 3});
    while (!q.empty())
    {
        auto v = q.front(); q.pop();
        int cx = v[0];
        int cy = v[1]; 
        int cd = v[2];
        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            int nd = i;
            int np = dist[cx][cy][cd] + (nd == cd ? 100 : 600);
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(board[nx][ny] == 1) continue;
            if(dist[nx][ny][nd] == -1 || np < dist[nx][ny][nd])
            {
                dist[nx][ny][nd] = np;
                q.push({nx, ny, nd});
            }
        }
    }
    answer = 987654321;
    for (int i = 0; i < 4; i++) if(dist[n-1][n-1][i] != -1) answer = min(answer, dist[n-1][n-1][i]);
    return answer;
}
