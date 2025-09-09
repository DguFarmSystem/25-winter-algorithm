#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N; 
    cin >> N;
    unordered_map<int, int> m;
    int num;

    while(N--) {
        cin >> num;
        if(m[num] == 0) {
            m[num] = 1;
        } else {
            m[num] += 1;
        }
    }
    
    int M;
    cin >> M;
    while(M--) {
        cin >> num;
        cout << m[num] << " ";
    }
    
    return 0;
}