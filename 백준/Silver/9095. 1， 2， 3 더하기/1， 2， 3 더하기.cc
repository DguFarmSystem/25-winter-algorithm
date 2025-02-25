#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int answer = 0;
    
    int T;
    cin >> T;
    
    int n;
    vector<int> v(12, 0);
    while(T--) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            if(i == 1) {
                v[i] = 1;
            } else if(i == 2) {
                v[i] = 2;
            } else if(i == 3) {
                v[i] = 4;
            } else {
                v[i] = v[i-3] + v[i-2] + v[i-1];
            }
        }
        cout << v[n] << '\n';
    }
    
    return 0;
}