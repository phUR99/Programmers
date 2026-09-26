#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int k = K;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto i : scoville) pq.push(i);
    while (pq.top() < k && pq.size() > 1)
    {
        int a = pq.top(); pq.pop();
        int b = 2 * pq.top(); pq.pop();
        pq.push(a+b);
        answer++;
    }
    if(pq.top() < k) answer = -1;
    
    return answer;
}