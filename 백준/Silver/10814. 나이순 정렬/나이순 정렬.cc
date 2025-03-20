#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<pair<int, int>, string>& a, const pair<pair<int, int>, string>& b) {
    if(a.first.first == b.first.first) {
        return a.first.second < b.first.second;
    }
    
    return a.first.first < b.first.first;
}

int main()
{
    int N;
    cin >> N;
    vector<pair<pair<int, int>, string>> v(N);
    
    for(int i = 0; i < N; i++) {
        cin >> v[i].first.first >> v[i].second;
        v[i].first.second = i;
    }
    
    sort(v.begin(), v.end(), compare);
    
    for(pair<pair<int, int>, string> i : v) cout << i.first.first << " " << i.second << '\n';

    return 0;
}