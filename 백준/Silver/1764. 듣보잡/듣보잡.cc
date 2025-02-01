#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    unordered_set<string> unheard;
    vector<string> unheard_unseen;
    
    string name;
    for (int i = 0; i < N; i++) {
        cin >> name;
        unheard.insert(name);
    }
    
    for (int i = 0; i < M; i++) {
        cin >> name;
        if (unheard.find(name) != unheard.end()) {
            unheard_unseen.push_back(name);
        }
    }
    
    sort(unheard_unseen.begin(), unheard_unseen.end());
    
    cout << unheard_unseen.size() << "\n";
    for (const string &person : unheard_unseen) {
        cout << person << "\n";
    }
    
    return 0;
}