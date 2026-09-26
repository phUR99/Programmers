#include <string>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
#include <iostream>
//  d l r u
//  d l l 
using namespace std;
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};

int visit[55][55][2505];

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    queue<vector<int>> q;
    q.push({x, y, 0});
    for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) for (int l = 0; l <= k; l++) visit[i][j][l] = -1;
    
    visit[x][y][0] = 0;
    while(!q.empty())
    {
        auto t = q.front(); q.pop();
        int cx = t[0];
        int cy = t[1];
        int ct = t[2];
        for (int i =0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if(visit[nx][ny][ct + 1] == -1)
            {
                visit[nx][ny][ct + 1] = i;
                q.push({nx, ny, ct + 1});
            }
        }
    }
    if(visit[r][c][k] == -1) answer = "impossible";
    else
    {
        int xx = r;
        int yy = c;
        int kk = k;
        while(kk != 0)
        {
            int pp = visit[xx][yy][kk];
            if(pp == 0)            
                {answer += 'd'; xx -= dx[0]; yy -= dy[0];}            
            else if(pp == 1)
                {answer += 'l'; xx -= dx[1]; yy -= dy[1];}               
            else if(pp == 2)
                {answer += 'r'; xx -= dx[2]; yy -= dy[2];}               
            else 
                {answer += 'u'; xx -= dx[3]; yy -= dy[3];}                                                                       
            kk--;    
            // cout << xx << yy << '\n';
        }
   
        reverse(answer.begin(), answer.end());

    }
    return answer;
}