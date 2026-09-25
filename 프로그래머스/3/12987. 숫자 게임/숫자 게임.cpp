#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    multiset<int> ms;
    for (auto b : B)
        ms.insert(b);
    // sort(A.begin(), A.end(), less<>());    
    for (auto a : A)
    {
        auto pos = ms.upper_bound(a);
        if(pos == ms.end()) continue;
        ms.erase(pos);
        answer++;
    }

    return answer;
}