#include <bits/stdc++.h>

using namespace std;

void permu(vector<int> v, vector<int> vv, int M) {
    if(M == vv.size()) {
        for(int i : vv) {
            cout << i << " ";
        }
        cout << '\n';
        return;
    }
    for(int i = 0; i < v.size(); i++) {
        //if(find(vv.begin(), vv.end(), v[i]) != vv.end()) continue;
        if(!vv.empty()) {
            auto max_it = max_element(vv.begin(), vv.end());
            if(*max_it > v[i]) continue;
        }
        
        vv.push_back(v[i]);
        permu(v, vv, M);
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
    permu(v, vv, M);
    
    return 0;
}