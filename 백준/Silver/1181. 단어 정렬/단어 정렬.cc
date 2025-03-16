#include <bits/stdc++.h>
using namespace std;

bool compare(string a, string b) {
    if(a.size() == b.size()) {
        return a < b;
    } else {
        return a.size() < b.size();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    
    vector<string> v;
    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    
    sort(v.begin(), v.end(), compare);
    string ps;
    for(string s : v) {
        if(ps == s) continue;
        cout << s << '\n';
        ps = s;
    }
    
    return 0;
}
