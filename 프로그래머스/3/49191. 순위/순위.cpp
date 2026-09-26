#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool graph[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    // 승패 결과 그래프 초기화
    for (int i = 0; i < results.size(); i++) {
        int a = results[i][0];
        int b = results[i][1];
        graph[a][b] = true; // a가 b를 이김
    }
    
    // 플로이드-워셜 알고리즘 적용 (k: 거쳐가는 선수, i: 승리한 선수, j: 패배한 선수)
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (graph[i][k] && graph[k][j]) {
                    graph[i][j] = true;
                }
            }
        }
    }
    
    // 각 선수별로 다른 모든 선수와의 승패를 알 수 있는지 확인
    for (int i = 1; i <= n; i++) {
        int count = 0;
        for (int j = 1; j <= n; j++) {
            if (graph[i][j] || graph[j][i]) {
                count++;
            }
        }
        if (count == n - 1) {
            answer++;
        }
    }
    
    return answer;
}
