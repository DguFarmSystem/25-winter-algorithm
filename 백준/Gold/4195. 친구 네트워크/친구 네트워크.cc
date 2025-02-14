#include <bits/stdc++.h>
using namespace std;

class UnionFind {
public:
    unordered_map<string, string> parent;
    unordered_map<string, int> size;
    
    string find(string s) {
        if(parent.find(s) == parent.end()) {
            parent[s] = s;
            size[s] = 1;
        }
        if(parent[s] == s) return s;
        return parent[s] = find(parent[s]);
    }
    
    void unite(string p1, string p2) {
        string np1 = find(p1);
        string np2 = find(p2);
        if(np1 != np2) {
            parent[np2] = np1;
            size[np1] += size[np2];
        }
    }
    
    int getSize(string p) {
        p = find(p);
        return size[p];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    
    while(T--) {
        int n;
        cin >> n;
        UnionFind uf;
        
        for(int i = 0; i < n; i++) {
            string p1, p2;
            cin >> p1 >> p2;
            uf.unite(p1, p2);
            cout << uf.getSize(p1) << '\n';
        }
    }

    return 0;
}