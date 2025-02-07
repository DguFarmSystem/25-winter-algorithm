#include <bits/stdc++.h>
using namespace std;

int arr[5][5][5];
int visited[5][5][5];
int C_MAP[5][5][5];
int dz[] = {0, 0, 0, 0, 1, -1};
int dy[] = {-1, 0, 1, 0, 0, 0};
int dx[] = {0, 1, 0, -1, 0, 0};
int min_distance = INT_MAX;

struct Point {
    int x;
    int y;
    int z;
};

void bfs(int C_MAP2[5][5][5]) {
    if(C_MAP2[0][0][0] == 0 || C_MAP2[4][4][4] == 0) return;
    
    memset(visited, 0, sizeof(visited));
    queue<Point> q;
    Point p = {0, 0, 0};
    q.push(p);
    visited[p.x][p.y][p.z] = 1;
    
    
            
    while(q.size()) {
        Point temp = q.front();
        q.pop();
        if(temp.x == 4 && temp.y == 4 && temp.z == 4) {
            min_distance = min(min_distance, visited[temp.x][temp.y][temp.z]);
            
            return;
        }
        
        for(int i = 0; i < 6; i++) {
            int nz = temp.z + dz[i];
            int ny = temp.y + dy[i];
            int nx = temp.x + dx[i];
            if(nz < 0 || nz >= 5 || ny < 0 || ny >= 5 || nx < 0 || nx >= 5) continue;
            if(visited[nx][ny][nz]) continue;
            if(C_MAP2[nx][ny][nz] == 1) {
                visited[nx][ny][nz] = visited[temp.x][temp.y][temp.z] + 1;
                Point p1 = {nx, ny, nz};
                q.push(p1);
            }
            
        }
    }
    return;
}

void Make_Maze(vector<int> v_order, vector<int> v_turn) {
    // memcpy(C_MAP, arr, sizeof(arr));
    int C_MAP2[5][5][5];
    for(int k = 0; k < 5; k++) {
        for(int j = 0; j < 5; j++) {
            for(int i = 0; i < 5; i++) {
                if(v_turn[k] == 0) {
                    C_MAP[i][j][k] = arr[i][j][k];
                    // continue;
                } else if (v_turn[k] == 1) {
                    C_MAP[i][j][k] = arr[j][4-i][k];
                } else if (v_turn[k] == 2) {
                    C_MAP[i][j][k] = arr[4-i][4-j][k];
                } else if (v_turn[k] == 3) {
                    C_MAP[i][j][k] = arr[4-j][i][k];
                }
            }
        }
    }
    for(int k = 0; k < 5; k++) {
        for(int n = 0; n < 5; n++) {
            if(v_order[n] == k+1) {
                for(int i = 0; i < 5; i++) {
                    for(int j = 0; j < 5; j++) {
                        C_MAP2[i][j][n] = C_MAP[i][j][v_order[n] - 1];
                    }
                }
            }
        }
    }
    bfs(C_MAP2);
}

void Make_Maze_Turn_Order(int n, vector<int> v_turn, vector<int> v_order) {
    if(n == 5) {
        // for(int i : v_turn) cout << i << " ";
        // cout << '\n';
        
        Make_Maze(v_order, v_turn);
        return;
    }
    for(int i = 0; i < 4; i++) {
        v_turn.push_back(i);
        Make_Maze_Turn_Order(n + 1, v_turn, v_order);
        v_turn.pop_back();
    }
}

void Make_Maze_Order(int depth, vector<int> v_order) {
    if(depth == 5) {
        // for(int i : v_order) cout << i << " ";
        // cout << '\n';
        
        vector<int> v_turn;
        Make_Maze_Turn_Order(0, v_turn, v_order);
        return;
    }
    for(int i = depth; i < 5; i++) {
        swap(v_order[i], v_order[depth]);
        Make_Maze_Order(depth + 1, v_order);
        swap(v_order[i], v_order[depth]);
    }
    return;
}

int main()
{
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            for(int k = 0; k < 5; k++) {
                cin >> arr[k][j][i];
            }
        }
    }
    vector<int> v_order = {1, 2, 3, 4, 5};
    Make_Maze_Order(0, v_order);

    if(min_distance == INT_MAX) {
        cout << -1;
    } else {
        min_distance--;
        cout << min_distance;
    }
    
    return 0;
}