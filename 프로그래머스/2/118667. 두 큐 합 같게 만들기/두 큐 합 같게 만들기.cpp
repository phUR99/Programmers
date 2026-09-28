#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -2;
    queue<int> q1, q2;
    int n = 4 * queue1.size() + 1;
    long long t1 = 0, t2 = 0;
    for (auto p : queue1) 
    {
        q1.push(p);
        t1 += p;
    }
    for (auto p : queue2) 
    {
        q2.push(p);
        t2 += p;
    }
    int cnt = 0;
    while(n--)
    {
        if(t1 == t2) return cnt;
        if(t1 > t2)
        {
            int p = q1.front();q1.pop();
            t1 -= p;
            t2 += p;
            q2.push(p);
        }
        else
        {
            int p = q2.front();q2.pop();
            t1 += p;
            t2 -= p;
            q1.push(p);
        }
        cnt++;
    }
    answer = -1;
    return answer;
}