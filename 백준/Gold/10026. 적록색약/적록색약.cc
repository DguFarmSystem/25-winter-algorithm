#include <bits/stdc++.h>
using namespace std;

int N;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
char arr[101][101];
int visited[101][101];

void dfs(int y, int x) {
    visited[y][x] = 1;
    
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny >= N || ny < 0 || nx >= N || nx < 0) continue;
        if(!visited[ny][nx] && arr[y][x] == arr[ny][nx]) {
            dfs(ny, nx);
        }
    }
    return;
}

void dfs2(int y, int x) {
    visited[y][x] = 1;
    
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny >= N || ny < 0 || nx >= N || nx < 0) continue;
        if(visited[ny][nx]) continue;
        if(arr[y][x] == 'R' || arr[y][x] == 'G') {
            if(arr[ny][nx] == 'R' || arr[ny][nx] == 'G') {
                dfs2(ny, nx);
            }
        } else {
            if(arr[ny][nx] == 'B') {
                dfs2(ny, nx);
            }
        }
            
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    
    int first = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(!visited[i][j]) {
                dfs(i, j);
                first++;
            }
        }
    }
    
    memset(visited, 0, sizeof(visited));
    
    int second = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(!visited[i][j]) {
                dfs2(i, j);
                second++;
            }
        }
    }
    
    cout << first << " " << second << '\n';
    
    return 0;
}
