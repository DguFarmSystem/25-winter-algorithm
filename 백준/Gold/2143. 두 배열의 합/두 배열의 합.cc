#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T, n, m;
    cin >> T >> n;
    vector<int> v1;
    int num;
    for(int i = 0; i < n; i++) {
        cin >> num;
        v1.push_back(num);
    }
    vector<int> v1_psum;
    for(int i = 0; i < n; i++) {
        v1_psum.push_back(v1[i]);
        for(int j = i+1; j < n; j++) {
            v1_psum.push_back(v1_psum.back() + v1[j]);
        }
    }
    // for(int i : v1_psum) cout << i << " ";
    // cout << '\n';
    // combi(v1, v1_psum, n, 0, 1);
    sort(v1_psum.begin(), v1_psum.end());
    
    cin >> m;
    vector<int> v2;
    for(int i = 0; i < m; i++) {
        cin >> num;
        v2.push_back(num);
    }
    vector<int> v2_psum;
    for(int i = 0; i < m; i++) {
        v2_psum.push_back(v2[i]);
        for(int j = i+1; j < m; j++) {
            v2_psum.push_back(v2_psum.back() + v2[j]);
        }
    }
    // for(int i : v2_psum) cout << i << " ";
    // cout << '\n';
    // combi(v2, v2_psum, m, 0, 2);
    sort(v2_psum.begin(), v2_psum.end());
    unordered_map<int, int> Map;
    for(int i : v2_psum) {
        if(Map[i]) {
            Map[i]++;
        } else {
            Map[i] = 1;
        }
    }
    
    long total = 0;
    int a;
    for(int i = 0; i < v1_psum.size(); i++) {
        a = T - v1_psum[i];
        if(Map[a]) total += Map[a];
    }
    cout << total;
    
    return 0;
}