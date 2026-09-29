#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int cnt = 0;
    for (auto ch : s)
    {
        if (ch == '(') cnt++;
        else
        {
            if (cnt == 0) return false;
            cnt--;
        }
    }
    if(cnt) return false;
    return answer;
}