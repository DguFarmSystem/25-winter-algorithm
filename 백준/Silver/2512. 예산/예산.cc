#include <bits/stdc++.h>
using namespace std;
int Max = 0;
int Max2 = 0;
int Min = INT_MAX;

int main()
{
    int N;
    cin >> N;
    
    vector<int> v(N, 0);
    int sum = 0;
    for(int i = 0; i < N; i++) {
        cin >> v[i];
        Max = max(Max, v[i]);
        Min = min(Min, v[i]);
        sum += v[i];
    }
    
    int M;
    cin >> M;
    
    if(sum <= M) {
        cout << Max;
    } else {
        long long left = 1;
        long long right = Max;
        long long middle;
        
        while(left <= right) {
            middle = (left + right) / 2;
            int total = 0;
            
            // cout << "middle: " << middle << '\n';
            
            for(int i = 0; i < N; i++) {
                if(v[i] <= middle) {
                    total += v[i];
                } else {
                    total += middle;
                }
            }
            
            if(total < M) {
                left = middle + 1;
                Max = middle;
            } else if(total > M) {
                right = middle - 1;
            } else {
                Max = middle;
                break;
            }
        }
        cout << Max;
    }
    
    return 0;
}