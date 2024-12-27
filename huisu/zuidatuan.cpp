#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MaxClique {
public:
    MaxClique(int n) : n(n), graph(n, vector<int>(n, 0)), maxCliqueSize(0) {}

    void addEdge(int u, int v) {
        graph[u][v] = graph[v][u] = 1;
    }

    void findMaxClique() {
        vector<int> currentClique;
        vector<int> candidates(n);
        for (int i = 0; i < n; ++i) {
            candidates[i] = i;
        }
        backtrack(currentClique, candidates);
    }

    int getMaxCliqueSize() const {
        return maxCliqueSize;
    }

private:
    int n;
    vector<vector<int>> graph;
    int maxCliqueSize;

    void backtrack(vector<int>& currentClique, vector<int>& candidates) {
        if (candidates.empty()) {
            maxCliqueSize = max(maxCliqueSize, (int)currentClique.size());
            return;
        }

        while (!candidates.empty()) {
            int v = candidates.back();
            candidates.pop_back();

            vector<int> newCandidates;
            for (int u : candidates) {
                if (graph[v][u]) {
                    newCandidates.push_back(u);
                }
            }

            currentClique.push_back(v);
            backtrack(currentClique, newCandidates);
            currentClique.pop_back();
        }
    }
};

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    MaxClique mc(n);

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        mc.addEdge(u, v);
    }

    mc.findMaxClique();
    cout << "Maximum clique size: " << mc.getMaxCliqueSize() << endl;

    return 0;
}