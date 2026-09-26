#include <string>
#include <vector>
#include <iostream>
// 5 -> 3 -> 4 -> 5 -> .. 최소값의 최대
// int x : x 이상인 돌만 밟을 때 stone을 전부 넘어갈 수 있나?
// x가 성공했을 때... x 미만은 볼 필요 없이 성공 x 초과는 시도해보기
using namespace std;
vector<int> arr;
int sp;

int match(int x)
{
    int pos = -1;

    while (1)
    {        
        bool changed = false;
        // cout << pos << ' ';
        for(int tmp = 1; tmp <= sp; tmp++)
        {
            int nxt = pos + tmp;            
            if(nxt >= arr.size()) return 1;
            if(arr[nxt] >= x)
            {
                changed = true;
                pos = nxt;
                break;
            }
        }
        if (!changed) break;
    }
    return 0;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    arr = stones;
    sp = k;
    int l = 1;
    int r = 2e8 + 1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if(match(m))
        {
            answer = m;
            l = m + 1;
        } 
        else
        {
            r = m - 1;
        }
    }    
    return answer;
} 