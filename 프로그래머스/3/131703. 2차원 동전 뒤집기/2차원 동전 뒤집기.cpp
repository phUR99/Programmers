#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    int answer = 987654321;
    int n = beginning.size();
    int m = beginning[0].size();
    int total = (1 << (n + m));
    for (int state = 0; state < total; state++)
    {
        vector<vector<int>> now = beginning;
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            int p = state & (1 << i);
            if(!p) continue;
            cnt++;
            for (int j = 0; j < m; j++) now[i][j] = !now[i][j];
        }
        for(int i = 0; i < m; i++)
        {
            int p = state & (1 << (i + n));
            if(!p) continue;
            cnt++;
            for (int j = 0; j < n; j++) now[j][i] = !now[j][i];
        }
        
        for (int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++) if(now[i][j] != target[i][j]) cnt = 987654321;
        }
        answer = min(cnt, answer);
    }
    if(answer == 987654321) answer = -1;
    
    return answer;
}