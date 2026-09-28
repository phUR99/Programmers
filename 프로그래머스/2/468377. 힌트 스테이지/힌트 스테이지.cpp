#include <string>
#include <vector>
#include <string.h>
#include <iostream>
#define INF 1987654321
using namespace std;
int n;
int dp[20][1<<16];

int dfs(int idx, int state, vector<vector<int>> &cost, vector<vector<int>> &hint)
{            
    if(idx == n) 
        return 0;
    int &ret = dp[idx][state];
    if(ret != -1) 
        return ret;
    int cnt = 0;
    for (int k = 0; k < hint.size(); k++)
    {
        auto &h = hint[k];
        if(!(state & (1 << k))) continue;
        for (int i = 1; i < h.size(); i++) if(h[i] == idx + 1) cnt++;
    }
    ret = INF;
    cnt = min(n - 1, cnt);
    ret = min(ret, cost[idx][cnt] + dfs(idx + 1, state, cost, hint));
    if(idx < hint.size())
    {
        ret = min(ret, cost[idx][cnt] + hint[idx][0] + dfs(idx + 1, (state | (1 << idx)), cost, hint));
    }
    return ret;    
}

int solution(vector<vector<int>> cost, vector<vector<int>> hint) {
    int answer = 0;
    n = cost.size();
    memset(dp, -1, sizeof(dp));
    int state = 0;
    answer = dfs(0, 0, cost, hint);

    
    return answer;
}