#include <string>
#include <vector>

using namespace std;

vector<int> num;
int n;
int t;

int dfs(int idx, int res)
{
    if(idx == n) return (res == t);
    
    int ret = 0;
    ret += dfs(idx + 1, res - num[idx]);
    ret += dfs(idx + 1, res + num[idx]);
    return ret;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    num = numbers;
    n = numbers.size();
    t = target;
    answer = dfs(0, 0);
    return answer;
}