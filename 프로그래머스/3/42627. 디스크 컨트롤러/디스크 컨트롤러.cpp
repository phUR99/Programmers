#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<vector<int>> jobs)
{
    sort(jobs.begin(), jobs.end());
    priority_queue<pair<int, int>> pq;

    int idx = 0;
    int ed = 0;
    int answer = 0;

    while (idx < jobs.size() || !pq.empty())
    {
        while (idx < jobs.size() && jobs[idx][0] <= ed)
        {
            int t = jobs[idx][0];
            int d = jobs[idx][1];

            pq.push({-d, -t});
            idx++;
        }

        if (pq.empty())
        {
            ed = jobs[idx][0];
            continue;
        }

        int d = -pq.top().first;
        int t = -pq.top().second;
        pq.pop();

        ed += d;
        answer += ed - t;
    }

    return answer / jobs.size();
}