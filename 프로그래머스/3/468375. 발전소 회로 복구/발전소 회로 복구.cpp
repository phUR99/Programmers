#include <string>
#include <vector>
#include <string.h>
#include <queue>
#include <iostream>
#define INF 987654321
using namespace std;
int k;
int dp[16][1<<16]; // 현재 i 번 Panel에 위치하고 상태가 State일 때. State == (1 << k) 일때까지의 이동의 최솟값
int dist[42][42];
vector<vector<int>> seq;
vector<vector<int>> arr;
vector<string> mp;
int ex, ey;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int di[20][20];

int diff(int ai, int bi)
{
    if (di[ai][bi] != -1) return di[ai][bi];
    int fa = arr[ai][0];
    int fb = arr[bi][0];    
    queue<pair<int, int>> q;
    memset(dist, -1, sizeof(dist));
    int X = mp.size();
    int Y = mp[0].size();
    int ax = arr[ai][1];
    int ay = arr[ai][2];
    int bx = arr[bi][1];
    int by = arr[bi][2];
    
    if (fa == fb)
    {    
        q.push({ax, ay});        
        dist[ax][ay] = 0;
    }
    else
    {
        q.push({ex, ey});
        dist[ex][ey] = 0;
    }
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        int cx = cur.first;
        int cy = cur.second;
        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < 0 || nx >= X || ny < 0 || ny >= Y) continue;
            if (dist[nx][ny] != -1) continue;
            if (mp[nx][ny] == '#') continue;
            dist[nx][ny] = dist[cx][cy] + 1;
            q.push({nx, ny});
        }
    }
    
    if (fa == fb)
    {
        di[ai][bi] = dist[bx][by];
        di[bi][ai] = dist[bx][by];
        return di[bi][ai];
    }
    else
    {
        di[ai][bi] = dist[ax][ay] + dist[bx][by] + abs(fa - fb);
        di[bi][ai] = dist[ax][ay] + dist[bx][by] + abs(fa - fb);
        return di[bi][ai];
    }
        
}

int dfs(int idx, int state)
{
    
    if(state == (1 << k) - 1) return 0;
    
    int &ret = dp[idx][state];
    if (ret != -1) return ret;
    ret = INF;
    for (int i = 0; i < k; i++)
    {
        int s = state & (1 << i);
        if(s) continue;
        int f = 1;
        for (auto se : seq)
        {
            int a = se[0];
            int b = se[1];
            if (i != b) continue;
            int nxt = state & (1 << a);
            if (nxt)
                f &= 1;
            else
                f &= 0;
        }
        if(!f) continue;
        ret = min(ret, diff(idx, i) + dfs(i, state | (1 << i)));
    }
    return ret;
}


int solution(int h, vector<string> grid, vector<vector<int>> panels, vector<vector<int>> seqs) {
    int answer = 0;
    k = panels.size();
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == '@')
            {
                ex = i;
                ey = j;
            }
        }
    }
    for (auto &s : seqs)
    {
        s[0]--;
        s[1]--;
    }
    for (auto &p : panels)
    {
        p[0]--;
        p[1]--;
        p[2]--;
    }
    memset(dp, -1, sizeof(dp));
    memset(di, -1, sizeof(di));
    arr = panels;
    seq = seqs;
    mp = grid;
    answer = dfs(0, 0);
    return answer;
}