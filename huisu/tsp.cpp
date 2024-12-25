#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n; // 城市数量
vector<vector<int>> graph; // 城市之间的距离图
vector<bool> visited; // 访问标记数组
int bestCost = INT_MAX; // 最优解

void tsp(int currPos, int count, int cost) {
    if (count == n && graph[currPos][0]) {
        bestCost = min(bestCost, cost + graph[currPos][0]);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[currPos][i]) {
            visited[i] = true;
            tsp(i, count + 1, cost + graph[currPos][i]);
            visited[i] = false; // 回溯
        }
    }
}

int main() {
    // 示例图，0表示两个城市之间没有直接路径
    graph = {
        {0, 29, 20, 21},
        {29, 0, 15, 17},
        {20, 15, 0, 28},
        {21, 17, 28, 0}
    };
    n = graph.size();
    visited = vector<bool>(n, false);
    visited[0] = true; // 从城市0开始

    tsp(0, 1, 0); // 开始回溯搜索

    cout << "The minimum cost is " << bestCost << endl;
    return 0;
}
