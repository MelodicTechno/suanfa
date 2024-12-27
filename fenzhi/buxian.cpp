#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

struct Point {
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
};

struct Node {
    Point pt;
    int dist;
    Node(Point _pt, int _dist) : pt(_pt), dist(_dist) {}
};

bool isValid(int row, int col, int N, int M) {
    return (row >= 0) && (row < N) && (col >= 0) && (col < M);
}

int rowNum[] = {-1, 0, 0, 1};
int colNum[] = {0, -1, 1, 0};

int shortestPath(vector<vector<int>>& grid, Point src, Point dest) {
    int N = grid.size();
    int M = grid[0].size();

    if (grid[src.x][src.y] == 0 || grid[dest.x][dest.y] == 0)
        return -1;

    vector<vector<bool>> visited(N, vector<bool>(M, false));
    visited[src.x][src.y] = true;

    queue<Node> q;
    q.push(Node(src, 0));

    while (!q.empty()) {
        Node curr = q.front();
        Point pt = curr.pt;

        if (pt.x == dest.x && pt.y == dest.y)
            return curr.dist;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int row = pt.x + rowNum[i];
            int col = pt.y + colNum[i];

            if (isValid(row, col, N, M) && grid[row][col] == 1 && !visited[row][col]) {
                visited[row][col] = true;
                q.push(Node(Point(row, col), curr.dist + 1));
            }
        }
    }

    return -1;
}

int main() {
    int N, M;
    cout << "Enter the dimensions of the grid (N M): ";
    cin >> N >> M;

    vector<vector<int>> grid(N, vector<int>(M));
    cout << "Enter the grid (0 for blocked, 1 for open):" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    int ax, ay, bx, by;
    cout << "Enter the coordinates of point a (ax ay): ";
    cin >> ax >> ay;
    cout << "Enter the coordinates of point b (bx by): ";
    cin >> bx >> by;

    Point src(ax, ay);
    Point dest(bx, by);

    int dist = shortestPath(grid, src, dest);

    if (dist != -1)
        cout << "The shortest path from a to b is " << dist << endl;
    else
        cout << "No path exists from a to b" << endl;

    return 0;
}