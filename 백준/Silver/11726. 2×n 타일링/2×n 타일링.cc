#include <bits/stdc++.h>
using namespace std;
// 1 1 2 3 5 8 13 21 34 55

vector<long> dp(1002, -1);
vector<long> v = {1, 1};

long cal(long num) {
    // cout << dp[num] << '\n';
    if(num <= 1) {
        return dp[num];
    }
    if(dp[num] != -1) return dp[num];
    return dp[num] = (cal(num - 1) % 10007) + (cal(num - 2) % 10007);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    for(int i = 0; i < v.size(); i++) {
        dp[i] = v[i];
    }
    
    int N;
    cin >> N;
    cout << cal(N) % 10007;
    
    return 0;
}