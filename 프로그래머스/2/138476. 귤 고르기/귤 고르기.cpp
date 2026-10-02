#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> mp;
    for (auto i : tangerine) mp[i]++;
    vector<int> cnt;
    for (auto i : mp) cnt.push_back(i.second);
    sort(cnt.begin(), cnt.end(), greater<>());
    int total = 0;
    for (auto i : cnt)
    {
        total += i;
        answer++;
        if(total >= k) break;
    }
    return answer;
}