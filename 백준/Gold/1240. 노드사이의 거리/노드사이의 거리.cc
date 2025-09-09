#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adj[1001];
int visited[1001];

void bfs(int node1, int node2) {
    fill(visited, visited + 1001, 0);
    
    int total = 0;
    queue<int> q;
    q.push(node1);
    visited[node1] = 1;
    while(q.size()) {
        int temp = q.front();
        q.pop();
        for (auto [nextNode, dist] : adj[temp]) {
            if (visited[nextNode]) continue;
            visited[nextNode] = visited[temp] + dist;
            // visited[nextNode] += dist;
            // total += dist;
            // cout << nextNode << '\n';
            if (nextNode == node2) {
                visited[nextNode]--;
                cout << visited[nextNode] << '\n'; 
                return;
            }
            q.push(nextNode);
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
    
    for(int i = 1; i < N; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        int distance;
        cin >> distance;
        
        adj[node1].push_back({node2, distance});
        adj[node2].push_back({node1, distance});
    }
    for(int i = 0; i < M; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        bfs(node1, node2);
    }
    
    return 0;
}