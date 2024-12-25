#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int v, vector<vector<int>>& graph, vector<int>& color, int c) {
    for (int i = 0; i < graph.size(); i++) {
        if (graph[v][i] && c == color[i]) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(vector<vector<int>>& graph, int m, vector<int>& color, int v) {
    if (v == graph.size()) {
        return true; // 所有顶点都已着色
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c; // 尝试给顶点v着色为c
            if (graphColoringUtil(graph, m, color, v + 1)) {
                return true;
            }
            color[v] = 0; // 回溯
        }
    }
    return false;
}

bool graphColoring(vector<vector<int>>& graph, int m) {
    vector<int> color(graph.size(), 0); // 初始化所有顶点颜色为0（未着色）
    if (!graphColoringUtil(graph, m, color, 0)) {
        cout << "Solution does not exist" << endl;
        return false;
    }

    cout << "Solution exists: Following are the assigned colors" << endl;
    for (int i = 0; i < graph.size(); i++) {
        cout << " " << color[i];
    }
    cout << endl;
    return true;
}

int main() {
    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    int m = 3; // Number of colors
    graphColoring(graph, m);
    return 0;
}
