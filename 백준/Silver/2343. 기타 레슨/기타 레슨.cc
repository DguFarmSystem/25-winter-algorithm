#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    vector<int> v(N, 0);
    int low = 0;
    int high = 0;
    for(int i = 0; i < N; i++) {
        cin >> v[i];
        low = max(low, v[i]);
        high += v[i];
    }
    // cout << low << " " << high << '\n';
    
    int answer = high;
    
    while(low <= high) {
        int mid = (low + high) / 2;
        int sum = 0;
        int temp = 0;
        for(int i = 0; i < N; i++) {
            if((temp+v[i]) <= mid) {
                temp += v[i];
            } else {
                temp = v[i];
                sum++;
                // cout << v[i] << '\n';
            }
            
        }
        sum++;
        
        if(sum > M) {
            low = mid + 1;
        } else if(sum <= M) {
            high = mid - 1;
            answer = mid;
        } 
        // cout << sum << " " << mid << '\n';
    }
    cout << answer;

    return 0;
}