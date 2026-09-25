#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if (n > s)
        answer.push_back(-1);
    else
    {
        answer.resize(n, s/n);
        int idx = n - 1;
        n = s % n;        
        while (n--)
        {
            answer[idx--]++;
        }
    }
    return answer;
}