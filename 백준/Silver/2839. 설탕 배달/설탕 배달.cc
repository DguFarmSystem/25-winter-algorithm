#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int answer = 0;
    
    int N;
    cin >> N;
    if(N < 8) {
        if(N == 3 || N == 5) {
            answer = 1;
        }
        else if(N == 4 || N == 7) {
            answer = -1;
        }
        else {
            answer = 2;
        }
        cout << answer;
        return 0;
    }
    
    int num = 0;
    while(!(N >= 8 && N <= 12)) {
        N -= 5;
        num++;
    }
    if(N == 8 || N == 10) {
        answer = num + 2;
    } 
    else if(N == 9 || N == 11) {
        answer = num + 3;
    }
    else if(N == 12) {
        answer = num + 4;
    }
    cout << answer;
    
    return 0;
}