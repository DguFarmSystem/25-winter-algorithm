#include <bits/stdc++.h>
using namespace std;

vector<int> adj[300001];
vector<int> dist;

void bfs(int K, int X) {
    queue<int> q;
    q.push(X);
    dist[X] = 0;
    
    int T = 0;
    
    while(!q.empty()) {
        int temp = q.front();
        q.pop();
        
        for(int i : adj[temp]) {
            if(dist[i] != -1) continue;
            dist[i] = dist[temp] + 1;
            q.push(i);
        }
    }
    
    return;
}

int main()
{
    int N, M, K, X;
    cin >> N >> M >> K >> X;
    
    dist.assign(N+1, -1);
    
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    
    bfs(K, X);
    
    bool found = false;
    for(int i = 1; i <= N; i++) {
        if(dist[i] == K) {
            cout << i << '\n';
            found = true;
        }
    }
    
    if(!found) cout << -1 << '\n';
    
    return 0;
}