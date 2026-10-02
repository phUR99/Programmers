#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int l = 1;
    int r = 1;
    int sum = 0;
    while (l <= n)
    {
        while (r <= n && sum < n) 
        {            
            sum += r++;
        }
        if(sum == n) answer++;
        sum -= l++;
    }
    
    return answer;
}