#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int parent[105];
int find(int x)
{
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}
int merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b) return 0;
    if(a > b) swap(a, b);
    parent[b] = a;
    return 1;
}
    
bool cmp(const vector<int>& a, const vector<int>& b) {return a[2] < b[2];}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    for (int i = 0; i < n; i ++) parent[i] = i;
    sort(costs.begin(), costs.end(), cmp);
    for (auto cost : costs)
    {
        int a = cost[0];
        int b = cost[1];
        if(merge(a, b)) answer += cost[2];
    }    
    return answer;
}