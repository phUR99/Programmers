#include <string>
#include <vector>
#include <iostream>
using namespace std;
int res = 0;
int n;
vector<vector<int>> arr;

void dfs(int f, int state)
{
    int ret = 0;    
    for (int i = 0; i < n; i++)
    {
        int a = arr[i][0];
        int b = arr[i][1];
        int nxt = state & (1 << i);
        if(nxt || f < a) continue;        
        dfs(f - b, state | (1 << i));
    }
    
    for (int i = 0; i < n; i++) if(state & (1<<i)) ret++;
    res = max(ret, res);
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    arr = dungeons;
    n = arr.size();
    dfs(k, 0);
    answer = res;
    return answer;
}