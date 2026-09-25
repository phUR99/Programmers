#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <set>
using namespace std;

int match(const string &u, const string &b, int ui, int bi)
{ 
    if (bi == b.size() && ui == u.size()) return 1;
    int ret = 0;
    if (b[bi] == '*')
    {        
        ret = match(u, b, ui + 1, bi + 1);   
    }
    else
    {
        if(u[ui] == b[bi])
            return match(u, b, ui + 1, bi + 1);
    }
    return ret;
}
int n;
int visited[10];
set<int> res;
vector<vector<int>> arr;
void dfs(int idx, int state)
{
    if(idx == n)
    {
        res.insert(state);
        return;
    }
    for (auto now : arr[idx])
    {
        if(state & (1 << now)) continue;
        dfs(idx + 1, state | (1 << now));
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;    
    n = banned_id.size();
    arr.resize(n);
    
    memset(visited, -1, sizeof(visited));
    for (int i = 0; i < banned_id.size(); i++)
    {
        for (int j = 0; j < user_id.size(); j++)
        {
            if (match(user_id[j], banned_id[i], 0, 0))
            {
                arr[i].push_back(j);
            }
        }        
    }
    dfs(0, 0);
    answer = res.size();
    return answer;
}