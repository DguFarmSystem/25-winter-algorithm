#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M;
    cin >> N;
    set<int> s;
    int num;
    for(int i = 0; i < N; i++) {
        cin >> num;
        s.insert(num);
    }
    cin >> M;
    for(int i = 0; i < M; i++) {
        cin >> num;
        if(s.count(num)) {
           cout << 1 << '\n';   
        } else {
            cout << 0 << '\n';
        }
    }
    return 0;
}