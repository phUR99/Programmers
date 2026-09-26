#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool cmp(const vector<int>& a, const vector<int>& b)
{
    if (a[0] != b[0])
        return a[0] > b[0];

    return a[1] < b[1];
}

vector<vector<int>> arr;
int solution(vector<vector<int>> scores)
{
    int al = scores[0][0];
    int ar = scores[0][1];

    sort(scores.begin(), scores.end(), cmp);

    int maxSecond = -1;
    int answer = 1;

    for (auto &s : scores)
    {
        int first = s[0];
        int second = s[1];

        if (second < maxSecond)
        {
            if (first == al && second == ar)
                return -1;

            continue;
        }

        maxSecond = second;

        if (first + second > al + ar)
            answer++;
    }

    return answer;
}