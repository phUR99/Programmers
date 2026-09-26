#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<vector<int>> jobs)
{
    sort(jobs.begin(), jobs.end());

    // {작업시간, 요청시간}
    // priority_queue는 큰 값부터 나오므로 음수로 저장
    priority_queue<pair<int, int>> pq;

    int idx = 0;
    int ed = 0;
    int answer = 0;

    while (idx < jobs.size() || !pq.empty())
    {
        // 현재 ed까지 요청된 작업을 모두 큐에 넣는다.
        while (idx < jobs.size() && jobs[idx][0] <= ed)
        {
            int t = jobs[idx][0];
            int d = jobs[idx][1];

            pq.push({-d, -t});
            idx++;
        }

        // 현재 처리할 작업이 없다면
        // 다음 작업의 요청시간으로 이동
        if (pq.empty())
        {
            ed = jobs[idx][0];
            continue;
        }

        // 작업시간이 가장 짧은 작업 하나 처리
        int d = -pq.top().first;
        int t = -pq.top().second;
        pq.pop();

        ed += d;
        answer += ed - t;
    }

    return answer / jobs.size();
}