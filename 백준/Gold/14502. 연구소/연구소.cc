#include <bits/stdc++.h>
using namespace std;

int arr[10][10];
int visited[10][10];
vector<pair<int, int>> virus_pos;
vector<pair<int, int>> empty_pos;
int maxSize;
int N, M;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int bfs() {
    queue<pair<int, int>> q;
    int temp[10][10];
    memcpy(temp, arr, sizeof(arr));
    memset(visited, 0, sizeof(visited));
    
    for(auto [y, x] : virus_pos) {
        q.push({y, x});
        visited[y][x] = 1;
    }
    while(q.size()) {
        int y, x;
        tie(y, x) = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if(temp[ny][nx] != 0) continue;
            if(visited[ny][nx] == 1) continue;
            
            visited[ny][nx] = 1;
            temp[ny][nx] = 2;
            q.push({ny, nx});
        }
    }
    int total = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(temp[i][j] == 0) total++;
        }
    }
    return total;
}

void combi(int start, vector<pair<int, int>> v) {
    if(v.size() == 3) {
        maxSize = max(maxSize, bfs());
        return;
    }
    for(int i = start; i < empty_pos.size(); i++) {
        arr[empty_pos[i].first][empty_pos[i].second] = 1;
        v.push_back(empty_pos[i]);
        combi(i + 1, v);
        arr[empty_pos[i].first][empty_pos[i].second] =  0;
        v.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 0) empty_pos.push_back({i, j});
            if(arr[i][j] == 2) virus_pos.push_back({i, j});
        }
    }
    vector<pair<int, int>> v;
    combi(0, v);
    
    cout << maxSize;
    return 0;
}