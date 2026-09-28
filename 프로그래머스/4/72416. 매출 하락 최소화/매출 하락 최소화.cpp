#include <string>
#include <vector>
#define ll long long
using namespace std;

ll dp[300005][2];
vector<ll> arr;
vector<int> adj[300005];

void dfs(int cur)
{
    if (adj[cur].size() == 0)
    {
        dp[cur][0] = arr[cur];
        dp[cur][1] = 0;
        return;
    }
    ll p = 1e18;
    dp[cur][0] = arr[cur];
    for (auto nxt : adj[cur])
    {
        dfs(nxt);
        dp[cur][0] += min(dp[nxt][0], dp[nxt][1]);
        p = max((ll)0, min(p, dp[nxt][0] - dp[nxt][1]));
    }
    dp[cur][1] = dp[cur][0] + p - arr[cur];
}

int solution(vector<int> sales, vector<vector<int>> links) {
    int answer = 0;
    arr.push_back(0);
    for (auto s : sales) arr.push_back(s);
    for (auto l : links) adj[l[0]].push_back(l[1]);
    dfs(1);
    answer = min(dp[1][0], dp[1][1]);
    return answer;
}