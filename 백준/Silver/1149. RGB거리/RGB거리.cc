#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    
    int rgb[1000][3];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> rgb[i][j];
        }
    }

    int dp[1000][3];
    for(int i = 0; i < 3; i++) {
        dp[0][i] = rgb[0][i];
    }
    
    for(int i = 1; i < N; i++) {
        for(int j = 0; j < 3; j++) {
            dp[i][j] = min(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]) + rgb[i][j];
        }
    }
    
    int Min = min(dp[N-1][0], dp[N-1][1]);
    Min = min(Min, dp[N-1][2]);
    
    cout << Min;
    
    // for(int i = 0; i < N; i++) {
    //     for(int j = 0; j < 3; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    
    return 0;
}