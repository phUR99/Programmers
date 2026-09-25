#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define ll long long
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;    
    ll sum = 0;
    
    int l = 0;
    int r = 50000;
    int h = 0;
    while (l <= r)
    {
        int m = (l + r) /2;
        ll tmpN = 0;
        for (auto work : works)
        {
            ll diff = max((ll)0, (ll)work - m);
            tmpN += diff;
        }
        if (tmpN > n)
        {
            l = m + 1;
        }
        else
        {
            h = m;
            r = m - 1;
        }
    }
    sort(works.begin(), works.end(), greater<int>());
    for (auto &work : works)
    {
        ll diff = max((ll)0, (ll)work - h);
        work -= diff;
        n -= diff;
    }    
    for (auto work : works)
    {
        if (n && work > 0)
        {
            work--;
            n--;
        }        
        answer += work * work;            
    }
    
    return answer;
}