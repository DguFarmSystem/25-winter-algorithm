#include <bits/stdc++.h>
using namespace std;

void combi(vector<int> v, vector<int> vv, int start) {
    if(vv.size() == 6) {
        for(int i : vv) cout << i << " ";
        cout << '\n';
        return;
    }
    for(int i = start; i < v.size(); i++) {
        int t = 0;
        for(int j = 0; j < vv.size(); j++) {
            if(v[i] == vv[j]) {
                t = 1;
                break;
            }
        }
        if(t == 0) vv.push_back(v[i]);
        combi(v, vv, i+1);
        vv.pop_back();
    }
}

int main()
{
    int N;
    while(cin >> N) {
        if(N == 0) break;
        
        vector<int> v;
        int num;
        for(int i = 0; i < N; i++) {
            cin >> num;
            v.push_back(num);
        }
        
        vector<int> vv;
        combi(v, vv, 0);
        cout << '\n';
    }

    return 0;
}