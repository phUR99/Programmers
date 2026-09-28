#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <string.h>
using namespace std;
// y descend, x a ascend


map<int, int> mp;
int l[100005];
int r[100005];

void insert(int root, int node)
{
    if (root < node)
    {
        if(r[root] == -1) r[root] = node;
        else insert(r[root], node);
    }
    else
    {
        if(l[root] == -1) l[root] = node;
        else insert(l[root], node);
    }
    
}
vector<vector<int>> arr;
bool cmp(vector<int> &a, vector<int>&b)
{
    if (a[1] == b[1]) return a[0] < b[0];
    return a[1] > b[1];
}

void dfs(int node, vector<vector<int>> &ans)
{
    ans[0].push_back(mp[node]);
    if(l[node] != -1)dfs(l[node], ans);
    if(r[node] != -1)dfs(r[node], ans);
    ans[1].push_back(mp[node]);
}


vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;    
    memset(l, -1, sizeof(l));
    memset(r, -1, sizeof(r));    
    for (int i = 0; i < nodeinfo.size(); i++) mp[nodeinfo[i][0]] = i + 1;    
    arr = nodeinfo;
    sort(arr.begin(), arr.end(), cmp);
    int root = arr[0][0];
    
    for (int i = 1; i < arr.size(); i++)
    {
        int node = arr[i][0];
        insert(root, node);
    }
    answer.resize(2);
    dfs(root, answer);
    return answer;
}