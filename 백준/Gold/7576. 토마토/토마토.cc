#include <bits/stdc++.h>
using namespace std;

int arr[1001][1001];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int date = 0;
queue<pair<int, int>> q;

void bfs(int M, int N) {
    int temp = q.size();
    while(temp) {
        int y, x;
        tie(y, x) = q.front();
        q.pop();
        temp--;
        
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if(arr[ny][nx] == -1 || arr[ny][nx] == 1) continue;
            
            arr[ny][nx] = 1;
            q.push({ny, nx});
        }
    }
    date++;
    if(!q.empty()) bfs(M, N);
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int M, N;
    cin >> M >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 1) {
                q.push({i, j});
            }
        }
    }
    bfs(M, N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            // cout << arr[i][j] << " ";
            if(arr[i][j] == 0) {
                cout << -1;
                return 0;
            }
        }
        // cout << '\n';
    }
    
    if(date) date--;
    cout << date;
    
    return 0;
}