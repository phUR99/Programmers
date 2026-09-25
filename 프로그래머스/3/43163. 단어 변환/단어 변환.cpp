#include <string>
#include <vector>
#include <queue>
using namespace std;

int diff(string &a, string &b)
{
    int n = a.size();
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        ret += (a[i] != b[i]);
    }
    return (ret <= 1);
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    words.push_back(begin);
    vector<int> visited(words.size(), -1);    
    
    queue<int> q;
    q.push(words.size()-1);
    visited[words.size()-1] = 0;
    while(!q.empty())
    {
        int now = q.front(); q.pop();
        for (int nxt = 0; nxt < words.size(); nxt++)
        {
            int di = diff(words[now], words[nxt]);
            if(visited[nxt] != - 1) continue;
            if (di)
            {
                visited[nxt] = visited[now] + 1;
                q.push(nxt);
            }
        }
    }       
    
    for (int i = 0; i < words.size(); i++)
    {
        if(words[i] == target && visited[i] != -1)
        {
            answer = visited[i];
        }
    }   
    return answer;
}