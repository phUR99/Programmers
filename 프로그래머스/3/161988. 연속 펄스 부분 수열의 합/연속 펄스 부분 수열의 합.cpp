#include <string>
#include <vector>
#include <algorithm>
#define ll long long
// 결과값에 abs 되니... 일단 짝수 항에 -1 곱하고 시작
// 

using namespace std;
vector<int> arr;

long long solution(vector<int> sequence) {
    long long answer = 0;
    arr = sequence;
    for (int i = 0; i < arr.size(); i++)
    {
        if(i % 2 == 0) arr[i] = -arr[i];
    }
    vector<ll> pre;
    pre.push_back(0);
    ll sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum = sum + arr[i];
        pre.push_back(sum);
    }
    sort(pre.begin(), pre.end());
    answer = abs(pre[0] - pre.back());
    return answer;
}