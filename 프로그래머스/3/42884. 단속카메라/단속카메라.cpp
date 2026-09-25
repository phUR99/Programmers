#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    int ed = -987654321;
    sort(routes.begin(), routes.end(), cmp);
    for (auto r : routes)
    {
        if (r[0] > ed)
        {
            ed = r[1];
            answer++;
        }
    }
    
    return answer;
}