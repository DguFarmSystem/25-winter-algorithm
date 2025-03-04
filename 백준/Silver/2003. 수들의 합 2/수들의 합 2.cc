#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin >> N >> M;
    
    queue<int> q;
    vector<int> v;
    int num;
    for(int i = 0; i < N; i++) {
        cin >> num;
        v.push_back(num);
    }
    
    int count = 0;
    
    int total = v[0];
    int i = 1;
    q.push(v[0]);
    
    while(i != N || !q.empty()) {
        // cout << i << " " << total << '\n';
        if(total < M) {
            q.push(v[i]);
            total += v[i];
            if(i != N) i++;
            
        } else if(total == M) {
            count++;
            total -= q.front();
            q.pop();
        } else {
            total -= q.front();
            q.pop();
        }
        if(i == N && total < M) break;
    }
    if(q.front() == M) count++;
    cout << count;
    

    return 0;
}