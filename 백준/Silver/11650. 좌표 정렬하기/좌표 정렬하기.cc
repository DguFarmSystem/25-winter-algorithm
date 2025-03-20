#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<int, int>&a, const pair<int, int> b) {
    if(a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main()
{
    int N;
    cin >> N;
    
    int x, y;
    vector<pair<int, int>> v(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
    }
    
    sort(v.begin(), v.end(), compare);
    
    for(pair<int, int> i : v) {
        cout << i.first << " " << i.second << '\n';
    }

    return 0;
}