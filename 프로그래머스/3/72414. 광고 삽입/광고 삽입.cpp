#include <string>
#include <vector>
#include <iostream>
#define ll long long
using namespace std;

ll pre[500005];
int to_int(string st)
{
    int h = stoi(st.substr(0, 2));
    int m = stoi(st.substr(3, 2));
    int s = stoi(st.substr(6, 2));
    // cout << h << ' ' << m << ' ' << s << '\n';
    
    return h * 3600 + m * 60 + s;
    
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    int n = to_int(play_time);
    int k = to_int(adv_time);
    for(int i = 0; i <= n; i++) pre[i] = 0;
    
    
    for (auto l : logs)
    {
        int st = to_int(l.substr(0, 8));
        int ed = to_int(l.substr(9, 8));
        pre[st]++;
        pre[ed]--;
    }
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i] + pre[i-1];
    }
    ll sum = 0; // pre[0] ~ pre[k-1]
    for (int i = 0; i < k; i++)
    {
        sum += pre[i];
    }
    int idx = 0;
    ll M = sum;
    for (int i = 1; i + k - 1 <= n; i++)
    {
        sum += pre[i + k - 1];
        sum -= pre[i - 1];
        if (M < sum)
        {
            idx = i;
            M = sum;
        }
    }
    answer = "";
    int a = idx / 3600;
    int b = idx % 3600 / 60;
    int c = idx % 3600 % 60;
    if (a < 10) answer += "0" + to_string(a) + ":";
    else answer += to_string(a) + ":";
    if (b < 10) answer += "0" + to_string(b) + ":";
    else answer += to_string(b) + ":";
    if (c < 10) answer += "0" + to_string(c);
    else answer += to_string(c);
    return answer; 
}