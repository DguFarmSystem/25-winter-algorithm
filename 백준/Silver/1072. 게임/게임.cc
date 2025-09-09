#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long X, Y;
    cin >> X >> Y;
    
    int Z = (Y * 100) / X;
    
    int t = 0;
    int NZ = Z;
    if(Z >= 99) {
        cout << -1;
    } else {
        long long left = 1, right = 1e9, answer = -1;
        
        while(left <= right) {
            long long mid = (left + right) / 2;
            bool T = ((Y+mid) * 100) / (X+mid) > Z;
            if(T) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        cout << answer;
    }
    
    return 0;
}