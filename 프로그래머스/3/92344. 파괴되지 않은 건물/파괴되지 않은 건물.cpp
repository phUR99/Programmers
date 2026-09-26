#include <string>
#include <vector>

using namespace std;

int pre[1005][1005];

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    
    for (auto s : skill)
    {
        int ty = s[0];
        int r1 = s[1];
        int c1 = s[2];
        int r2 = s[3];
        int c2 = s[4];
        int de = s[5];
        if (ty == 1)
        {
            pre[r1][c1] -= de;
            pre[r1][c2 + 1] +=de;
            pre[r2 + 1][c1] += de;            
            pre[r2 + 1][c2 + 1] -= de;
        }
        else
        {
            pre[r1][c1] += de;
            pre[r1][c2 + 1] -=de;
            pre[r2 + 1][c1] -= de;
            pre[r2 + 1][c2 + 1] += de;
        }
        
    }
    for (int i =0; i < 1000; i++)
    {
        for (int j = 1; j <1000; j++)
        {
            pre[i][j] = pre[i][j] + pre[i][j-1];
        }
    }
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 1; j <1000; j++)
        {
            pre[j][i] = pre[j][i] + pre[j-1][i];
        }
    }
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            board[i][j] += pre[i][j];
            if(board[i][j] > 0) answer++;
        }
    }
    
    return answer;
}