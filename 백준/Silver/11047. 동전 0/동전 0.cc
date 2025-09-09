#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, K;
    cin >> N >> K;
    
    vector<int> v(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    
    int t = 0;
    for(int i = N-1; i >= 0; i--) {
        if(K == 0) break;
        if(v[i] <= K) {
            while(v[i] <= K) {
                K = K - v[i];
                t++;
            }
        }
    }
    
    cout << t;
    
    return 0;
}