#include <string>
#include <vector>
#include <string.h>
using namespace std;
int dp[2005];
int nn;

int dfs(int cur)
{
    if (cur ==  nn) return 1;
    int &ret = dp[cur];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 1; i <= 2;  i++)
    {
        int nxt = cur + i;
        if (nxt <= nn)
            ret += dfs(nxt);
            ret %= 1234567;
    }
    return ret;
}


long long solution(int n) {
    long long answer = 0;
    nn = n;
    memset(dp,  -1, sizeof(dp));
    answer = dfs(0);
    
    return answer;
}