#include <string>
#include <vector>
#include <string.h>

using namespace std;

int n;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    n = triangle.size();
    for (int row = n - 2; row >= 0; row--)
    {
        for (int col = 0; col <= row; col++)
        {
            triangle[row][col] = triangle[row][col] + max(triangle[row + 1][col], triangle[row + 1][col +1]);
        }
    }
    answer = triangle[0][0];
    

    return answer;
}