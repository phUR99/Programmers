#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(pair<double, int> &a, pair<double, int> &b)
{
    if(a.first == b.first) return a.second < b.second;
    else return a.first > b.first;
}

int ar[505];

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;    
    vector<pair<double, int>> arr;    
    int cnt = 0;
    int n = stages.size();
    
    for (int i = 0; i < n; i++) ar[stages[i]]++;
    for (int i = 1; i <=N; i++)
    {
        if(n == 0) arr.push_back({0, i});
        else arr.push_back({(double)ar[i] / n, i});
        n -= ar[i]; 
    }
    
    sort(arr.begin(), arr.end(), cmp);
    for (auto a : arr) answer.push_back(a.second);
    return answer;
}