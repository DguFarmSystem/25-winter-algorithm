#include <bits/stdc++.h>
using namespace std;

vector<long long> dp(105, -1);
vector<long long> v = {1, 1, 1, 2, 2};

long long cal(long long num) {
    if(num == 1) {
        return v[num-1];
    } else if( num == 2) {
        return v[num-1];
    } else if(num == 3) {
        return v[num-1];
    } else if(num == 4) {
        return v[num-1];
    } else if(num == 5) {
        return v[num-1];
    } else {
        if (dp[num] != -1) return dp[num];
        return dp[num] = cal(num - 1) + cal(num - 5);
    }
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
    long long num;
    for(int i = 0; i < N; i++) {
        cin >> num;
        cout << cal(num) << '\n';
    }

    return 0;
}