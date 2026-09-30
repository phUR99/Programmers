#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int dp[100005][2];
vector<int> adj[100005];
int pa[100005];


void dfs(int cur, int pre)
{
    if(pa[cur] != -1) return;
    pa[cur] = pre;
    for (int nxt : adj[cur])
    {
        dfs(nxt, cur);
    }
}

int func(int node, int turn)
{
    int &ret = dp[node][turn];
    if(ret != -1) return ret;
    ret = turn;    
    for (int nxt : adj[node])
    {
        if(pa[node] == nxt) continue;
        if(turn)
            ret += min(func(nxt, 0), func(nxt, 1));
        else
            ret += func(nxt, 1);
    }    
    return ret;
}

int solution(int n, vector<vector<int>> lighthouse) {
    int answer = 0;
    for (int i = 0; i <= n; i++) fill(dp[i], dp[i] + 2, -1);
    fill(pa, pa + n + 1, -1);

    for (auto i : lighthouse)
    {
        int a = i[0];
        int b = i[1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    answer = min(func(1, 0), func(1, 1));
    
    return answer;
}