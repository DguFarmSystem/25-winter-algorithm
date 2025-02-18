#include <bits/stdc++.h>
using namespace std;

vector<char> v[100];

void preorder(char A) {
    if(v[A].empty()) {
        cout << A;
    } else {
        cout << A;
        if(v[A][0] != '!') preorder(v[A][0]);
        if(v[A][1] != '!') preorder(v[A][1]);
    }
}

void inorder(char A) {
    if(v[A].empty()) {
        cout << A;
    } else {
        if(v[A][0] != '!') inorder(v[A][0]);
        cout << A;
        if(v[A][1] != '!') inorder(v[A][1]);
    }
}

void postorder(char A) {
    if(v[A].empty()) {
        cout << A;
    } else {
        if(v[A][0] != '!') postorder(v[A][0]);
        if(v[A][1] != '!') postorder(v[A][1]);
        cout << A;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    char a, b, c;
    for(int i = 0; i < N; i++) {
        cin >> a >> b >> c;
        if(b != '.') {
            v[a].push_back(b);
        } else {
            v[a].push_back('!');
        }
        if(c != '.') {
            v[a].push_back(c);
        } else {
            v[a].push_back('!');
        }
    }
    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');
    cout << '\n';
    return 0;
}
