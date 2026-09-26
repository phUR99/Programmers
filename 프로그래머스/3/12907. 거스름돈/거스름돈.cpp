#include <string>
#include <vector>

using namespace std;
int dp[100005];

int solution(int n, vector<int> money) {
    int answer = 0;
    dp[0] = 1;
    for (int p : money)
    {
        for (int i = p;  i <= n; i ++) dp[i] = dp[i] + dp[i-p];
    }
    answer = dp[n];
    return answer;
}