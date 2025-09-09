#include <bits/stdc++.h>
using namespace std;
int Max = 0;
int Max2 = 0;
int Min = INT_MAX;

int main()
{
    int K, N;
    cin >> K >> N;
    
    vector<int> v(K, 0);
    for(int i = 0; i < K; i++) {
        cin >> v[i];
        Max = max(Max, v[i]);
        Min = min(Min, v[i]);
    }
    
    long long left = 1;
    long long right = Max;
    long long middle = Min;
    long long total = 0;
    
    //middle이 Max일 때 시도
    for(int i = 0; i < K; i++) {
        total += v[i] / middle;
    }
    if(total >= N) Max2 = middle;
    
    while(left <= right) {
        middle = (left + right) / 2;
        total = 0;
        // cout << "middle: " << middle << '\n';
        
        for(int i = 0; i < K; i++) {
            total += v[i] / middle;
        }
        if(total >= N) {
            left = middle + 1;
            Max2 = middle;
        } else if(total < N) {
            right = middle - 1;
        }
    }

    
    cout << Max2;
    
    return 0;
}