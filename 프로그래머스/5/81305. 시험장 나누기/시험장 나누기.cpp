#include <string>
#include <vector>
#include <string.h>
using namespace std;
int l[10005];
int r[10005];
int p[10005];
int x[10005];
int root;


int dfs(int node, int lim, int &cnt)
{
    int lv = 0;
    int rv = 0;
    if(l[node] != -1) lv = dfs(l[node], lim, cnt);
    if(r[node] != -1) rv = dfs(r[node], lim, cnt);
    if (x[node] + lv + rv <= lim)
        return x[node] + lv + rv;
    if (x[node] + min(lv, rv) <= lim)
    {
        cnt++;
        return x[node] + min(lv, rv);
    }
    cnt +=2 ;
    return x[node];
}

int solve(int lim)
{
    int cnt = 0;
    dfs(root, lim, cnt);
    cnt++;
    return cnt;
}

int solution(int k, vector<int> num, vector<vector<int>> links) {
    int answer = 0;
    
    memset(l, -1, sizeof(l));
    memset(r, -1, sizeof(r));
    memset(p, -1, sizeof(p));
    for (int i = 0; i < links.size(); i++)
    {
        int ll = links[i][0];
        int rr = links[i][1];
        l[i] = ll;
        r[i] = rr;
        if(ll != -1) p[ll] = i;
        if(rr != -1) p[rr] = i;
        x[i] = num[i];
    }

    for (int i = 0; i < links.size(); i++) if(p[i] == -1) root = i;
    
    int ll = 0;
    for (int i = 0; i < num.size(); i++) ll = max(ll, num[i]);
    int rr = 1e8;
    while (ll <= rr)
    {
        int m = (ll + rr) /2;
        if(solve(m) <= k)
        {
            answer = m;
            rr = m - 1;
        }
        else
            ll = m + 1;
    }
    
    return answer;
}