#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    
    vector<int> v(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
    int temp = 0;
    int total = 0;
    for(int i : v) {
        temp += i;
        total += temp;
    }

    cout << total << '\n';
    
    return 0;
}