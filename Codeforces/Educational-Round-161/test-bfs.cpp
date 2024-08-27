#include <bits/stddc++.h>
using namespace std;

const int X[4] = {0, -1, 0, 1};
const int Y[4] = {-1, 0, 1, -1};
struct Point {
    pair<int, int> coor;
    int cost;
    bool dir; // true is vertical || false is horizion
    Point() {
        coor = make_pair(-1, -1); // toa do vi tri hien tai
        cost = -1;
        dir = false;
    }
    Point(pair<int, int> _coor, int _cost, bool _dir) {
        coor = _coor;
        cost = _cost;
        dir = _dir;
    }
};

void bfs(pair<int, int> start, pair<int, int> des, vector<vector<bool>> board, int numRow, int numCol) {
    queue<Point> q;
    q.push(Point(start, 0, false));
    vector<vector<bool>> visted;
    do {
        Point cur = q.front();
        q.pop();
        visited[x][y] = true;
        for(int i = 0; i < 4; i++) {
            int x = cur.coor.first;
            int y = cur.coor.second;
            if (isBoard(x, y) && !board[x][y] && !visited[x][y]) { // xet co trong bang hay khong, co vuot bien hay khong, co bi chan hay khong
                int stepCost, newDir, newCost;

                if (x == 0) newDir = false;
                else newDir = true;
                if (cur.dir != newDir) stepCost = 1; // khac huong
                else stepCost = 0;                   // cung huong

                newCost = cur.cost + stepCost;      // tim thayy dich
                if (make_pair(x, y) == des) {
                    cout << newCost;
                    return;
                }
                q.push(Point(make_pair(x, y), newCost, newDir)); // chua thayy thi push roi duyet tiep
            }
        }
    } while(!q.empty());
}
int main() {

}
