#include <string>
#include <vector>
#include <queue>

#define ll long long
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;    
    priority_queue<int, vector<int>> pq;
    for (auto work : works) pq.push(work);
    while (n--)
    {
        
        int h = pq.top(); 
        if(h == 0) break;
        pq.pop();
        pq.push(--h);
    }
    while(!pq.empty())
    {
        ll h = pq.top(); pq.pop();
        answer += h * h;
    }
    return answer;
}