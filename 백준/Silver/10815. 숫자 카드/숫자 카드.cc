#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    unordered_set<int> set;
    int num;
    for(int i = 0; i < N; i++) {
        cin >> num;
        set.insert(num);
    }
    
    int M;
    cin >> M;
    for(int i = 0; i < M; i++) {
        cin >> num;
        if(set.count(num)) {
            cout << 1 << " ";
        } else {
            cout << 0 << " ";
        }
    }

    return 0;
}