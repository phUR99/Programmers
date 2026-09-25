#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2, 0);
    multiset<int> ms;
    
    for (auto op : operations)
    {
        char ins = op[0];        
        int num = stoi(op.substr(2, op.size()-1));
        if(ins == 'I')
            ms.insert(num);
        if(ms.empty()) continue;
        if(ins == 'D' && num == -1)
        {
            int m = *(ms.begin());
            ms.erase(m);
        }
        if(ins == 'D' && num == 1)
        {
            int M = *(prev(ms.end()));
            ms.erase(M);
        }            
    }
    if (!ms.empty())
    {
        answer[0] = *(prev(ms.end()));
        answer[1] = *(ms.begin());    
    }
    
    
    return answer;
}