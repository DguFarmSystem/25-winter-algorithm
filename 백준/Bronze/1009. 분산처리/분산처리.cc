#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--) {
        int a, b;
        cin >> a >> b;
        int c = 1;
        for(int i = 0; i < b; i++) {
            c = ((a % 10) * (c % 10)) % 10;
        }
        if(c == 0) {
            cout << 10 << '\n';
        } else {
            cout << c << '\n';
        }
    }

    return 0;
}