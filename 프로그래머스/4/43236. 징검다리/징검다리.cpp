#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;

bool func(int x, int n)
{
    int cnt = 0;
    int pre = 0;

    for (int cur : arr)
    {
        if (cur - pre < x)
        {
            cnt++;
        }
        else
        {
            pre = cur;
        }
    }

    return cnt <= n;
}

int solution(int distance, vector<int> rocks, int n)
{

    sort(rocks.begin(), rocks.end());
    rocks.push_back(distance);
    arr = rocks;    

    int l = 0;
    int r = distance;
    int answer = 0;

    while (l <= r)
    {
        int m = (l + r) / 2;

        if (func(m, n))
        {
            answer = m;
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }

    return answer;
}