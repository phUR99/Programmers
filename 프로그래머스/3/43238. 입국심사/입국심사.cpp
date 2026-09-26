#include <string>
#include <vector>
// 시간 T 매개변수 탐색
using namespace std;

#define ll long long


int p;
vector<int> arr;

int func(ll x)
{
    ll ret = 0;
    for (int a : arr)
    {
        ret += x / a;
    }
    return ret >= (ll)p;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    arr = times;
    p = n;
    ll l = 0;
    ll r = 1e18;
    while (l <= r)
    {
        ll m = (l + r) / 2;
        if (func(m))
        {
            answer = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }

    return answer;
}