#include <bits/stdc++.h>
using namespace std;

int total = 0;
int visited[1001];

void dfs(int node, vector<int> v[]) {
    visited[node] = 1;
    // cout << node << " ";
    
    for(int next : v[node]) {
        if(!visited[next]) {
            dfs(next, v);
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    int a, b;
    vector<int> v[1001];
    
    for(int i = 0; i < M; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    for(int i = 1; i <= N; i++) {
        if(!visited[i]) {
            dfs(i, v);
            total++;
        }
    }

    cout << total;
    
    return 0;
}
