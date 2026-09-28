#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
// y descend, x a ascend

vector<vector<int>> arr;
map<int, int> mp;
vector<vector<int>> ans;

void dfs(int i, int l, int r)
{

    if(l > r) return;
    int ml = -1, mr = -1;
    int nl = 0, nr = 0;
    for (int p = l; p < i; p++) 
    {
        if (ml < arr[p][1])
        {
            ml = arr[p][1];
            nl = p;
        }
    }
    for (int p = i + 1; p <= r; p++) 
    {
        if (mr < arr[p][1])
        {
            mr = arr[p][1];
            nr = p;
        }
    }
    // cout << mp[arr[i][0]] << ' ';
    ans[0].push_back(mp[arr[i][0]]);
    dfs(nl, l, i -1);
    dfs(nr, i +1, r);    
    ans[1].push_back(mp[arr[i][0]]);
}
    


vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    arr = nodeinfo;
    sort(arr.begin(), arr.end());
    ans.resize(2);
    
    int st = 0;
    int vl = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (vl < arr[i][1])
        {
            st = i;
            vl = arr[i][1];
        }        
    }
    for (int i = 0; i <nodeinfo.size(); i++) mp[nodeinfo[i][0]] = i + 1;
    
    dfs(st, 0, arr.size()-1);
    answer = ans;
    return answer;
}