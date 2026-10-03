#include <string>
#include <vector>
#include <queue>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs(const vector<string> &arr, int x, int y)
{
    queue<pair<int, int>> q;
    vector<vector<int>> dist(5, vector<int>(5, -1));
    q.push({x, y});
    dist[x][y] = 0;
    while(!q.empty())
    {
        auto tmp = q.front(); q.pop();
        int cx = tmp.first;
        int cy = tmp.second;
        for (int i = 0; i < 4; i++)
        {
            int nx = dx[i] + cx;
            int ny = dy[i] + cy;
            if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
            if(dist[nx][ny] != -1) continue;
            if(arr[nx][ny] == 'X') continue;
            dist[nx][ny] = dist[cx][cy] + 1;
            if(dist[nx][ny] <= 2 && arr[nx][ny] == 'P') return 0;
            q.push({nx, ny});
        }
    }
    return 1;
}

int match(const vector<string> &arr)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if(arr[i][j] != 'P') continue;            
            if(!bfs(arr, i, j)) return 0;
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (auto place : places)
    {
        answer.push_back(match(place));
    }
    
    return answer;
}