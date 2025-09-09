#include <bits/stdc++.h>

using namespace std;

void permu(vector<int> v, vector<int> vv, int M, int start) {
    if(M == vv.size()) {
        for(int i : vv) {
            cout << i << " ";
        }
        cout << '\n';
        return;
    }
    for(int i = start; i < v.size(); i++) {
        if(find(vv.begin(), vv.end(), v[i]) != vv.end()) continue;
        vv.push_back(v[i]);
        permu(v, vv, M, i);
        vv.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    vector<int> v;
    for(int i = 1; i <= N; i++) {
        v.push_back(i);
    }
    vector<int> vv;
    permu(v, vv, M, 0);
    
    return 0;
}