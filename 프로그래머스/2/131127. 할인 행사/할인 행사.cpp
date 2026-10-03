#include <string>
#include <vector>

using namespace std;
int n;
int pre[15];
int idx(const string &a, const vector<string> &arr) {
    for (int i = 0; i < n; i++)
    {
        if(a == arr[i]) return i;
    }
    return -1;
}



int check(const vector<int> &number)
{
    for (int i = 0; i < n; i++)
    {
        if (number[i] > pre[i]) return 0;   
    }
    return 1;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    n = want.size();
    for (int i = 0; i < 10; i++)
    {
        int id = idx(discount[i], want);
        if (id == -1) continue;
        pre[id]++;
    }
    answer = check(number);
    for (int i = 10; i < discount.size(); i++)
    {
        int id1 = idx(discount[i], want);
        int id2 = idx(discount[i - 10], want);
        if (id1 != -1) pre[id1]++;
        if (id2 != -1) pre[id2]--;
        answer += check(number);
    }
    
    return answer;
}