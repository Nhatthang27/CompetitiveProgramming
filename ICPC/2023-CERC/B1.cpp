#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

// Hàm tăng cặp ghép
void increaseMatching(int u, vector<int> &matchU, vector<int> &matchV,
                      vector<bool> &visited, const vector<vector<int>> &graph) {
    visited[u] = true;
    for (int v = 0; v < graph[u].size(); ++v) {
        if (!visited[v] && graph[u][v] == 0) {
            visited[v] = true;
            if (matchV[v] == -1 ||
                increaseMatching(matchV[v], matchU, matchV, visited, graph)) {
                matchU[u] = v;
                matchV[v] = u;
                return;
            }
        }
    }
}

// Hàm sửa nhãn
void relabelLabels(vector<int> &labelsX, vector<int> &labelsY,
                   const vector<vector<int>> &graph, const vector<int> &matchU,
                   const vector<int> &matchV) {
    int delta = INF;
    for (int u = 0; u < graph.size(); ++u) {
        if (matchU[u] == -1) {
            for (int v = 0; v < graph[u].size(); ++v) {
                if (matchV[v] == -1) {
                    delta = min(delta, labelsX[u] + labelsY[v] - graph[u][v]);
                }
            }
        }
    }

    for (int u = 0; u < labelsX.size(); ++u) {
        if (matchU[u] != -1) {
            labelsX[u] -= delta;
        }
    }

    for (int v = 0; v < labelsY.size(); ++v) {
        if (matchV[v] != -1) {
            labelsY[v] += delta;
        }
    }
}

// Hàm giải bài toán phân công bằng thuật toán Kuhn-Munkres
int maxProfitAssignment(const vector<vector<int>> &assignments) {
    int n = assignments.size();
    vector<int> matchU(n, -1); // Lưu cặp ghép của X
    vector<int> matchV(n, -1); // Lưu cặp ghép của Y
    vector<int> labelsX(n, 0); // Nhãn của các đỉnh trong X
    vector<int> labelsY(n, 0); // Nhãn của các đỉnh trong Y

    while (true) {
        // Bước 1: Tìm tập ghép không đầy đủ (đỉnh tự do)
        bool foundFreeVertex = false;
        for (int u = 0; u < n; ++u) {
            if (matchU[u] == -1) {
                vector<bool> visited(n, false);
                increaseMatching(u, matchU, matchV, visited, assignments);
                foundFreeVertex = true;
                break;
            }
        }
        if (!foundFreeVertex)
            break; // Nếu không còn đỉnh tự do, kết thúc thuật toán

        // Bước 3: Sửa nhãn
        relabelLabels(labelsX, labelsY, assignments, matchU, matchV);
    }

    // Tính tổng số tiền lớn nhất có thể kiếm được
    int maxProfit = 0;
    for (int u = 0; u < n; ++u) {
        if (matchU[u] != -1) {
            maxProfit += assignments[u][matchU[u]];
        }
    }

    return maxProfit;
}

int main() {
    int n;
    cout << "Nhap so luong nguoi va cong viec (n): ";
    cin >> n;

    vector<vector<int>> assignments(n, vector<int>(n));
    cout << "Nhap ma tran Cij:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> assignments[i][j];
        }
    }

    int maxProfit = maxProfitAssignment(assignments);
    cout << "Tong so tien lon nhat kiem duoc: " << maxProfit << endl;

    return 0;
}
