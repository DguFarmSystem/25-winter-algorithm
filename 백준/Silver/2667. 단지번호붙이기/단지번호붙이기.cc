#include <bits/stdc++.h>
using namespace std;
int arr[27][27];
int visited[27][27];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int N;
vector<int> v;

int dfs(int y, int x) {
    visited[y][x] = 1;
    int total = 1;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
        if(arr[ny][nx] == 1 && visited[ny][nx] == 0) {
            total += dfs(ny, nx);
        }
    }
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    string s;
    for(int i = 0; i < N; i++) {
        cin >> s;
        for(int j = 0; j < N; j++) {
            arr[i][j] = s[j] - '0';
        }
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(arr[i][j] == 1 && visited[i][j] == 0) {
                v.push_back(dfs(i, j));
            }
        }
    }
    
    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for(int i : v) cout << i << '\n';
    
    return 0;
}