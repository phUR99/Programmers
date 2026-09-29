#include <string>
#include <vector>
#include <iostream>
using namespace std;

string str = "123456789*0#";
    
pair<int, int> curpos(char tmp)
{
    int t = str.find(tmp);
    int x = t / 3;
    int y = t % 3;
    return {x, y};
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    pair<int, int> lpos, rpos;
    lpos = curpos('*');
    rpos = curpos('#');
    for (auto n : numbers)
    {
        char p = n + '0';
        if (n == 1 || n == 4 || n == 7)
        {
            answer += 'L';
            lpos = curpos(p);            
        }
        else if(n == 3 || n == 6 || n == 9)
        {
            answer += 'R';
            rpos = curpos(p);
        }
        else
        {
            auto pos = curpos(p);
            int ld = abs(pos.first - lpos.first) + abs(pos.second - lpos.second);
            int rd = abs(pos.first - rpos.first) + abs(pos.second - rpos.second);            
            if (ld == rd)
            {
                answer += (hand == "left" ? 'L' : 'R');
                if(hand == "left")
                    lpos = curpos(p);
                else
                    rpos = curpos(p);
            }
            else if (ld < rd)
            {
                answer += 'L';
                lpos = curpos(p);
            }
            else
            {
                answer += 'R';
                rpos = curpos(p);
            }
        }        
    }
    return answer;
}