#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    vector<int> stair(N+1, 0);
    
    for(int i = 1; i <= N; i++) {
        cin >> stair[i];
    }

    vector<int> dp(N+1, 0);

    dp[1] = stair[1];
    if (N > 1) {
        dp[2] = stair[1] + stair[2];
    }

    for (int i = 3; i <= N; i++) {
        dp[i] = max(dp[i-2] + stair[i], dp[i-3] + stair[i-1] + stair[i]);
    }

    cout << dp[N];

    return 0;
}
