#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    s += ' ';
    int idx = 0;
    int m = 987654321;
    int M = -987654321;
    while (s[idx] != '\0')
    {
        string tmp = "";
        while(s[idx] != ' ') tmp += s[idx++];
        int n = stoi(tmp);
        m = min(n, m);
        M = max(n, M);
        idx++;
    }
    answer += to_string(m);
    answer += ' ';
    answer += to_string(M);
    return answer;
}