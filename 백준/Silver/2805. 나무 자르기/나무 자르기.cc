#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int Max = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    int num;
    vector<int> v;
    
    for(int i = 0; i < N; i++) {
        cin >> num;
        Max = max(Max, num);
        v.push_back(num);
    }
    
    ll left = 0, right = Max;
    ll result = 0;
    
    while(left <= right) {
        ll middle = (left + right) / 2;
        ll total = 0;
        
        for(int i = 0; i < N; i++) {
            if(v[i] > middle) {
                total += v[i] - middle;
            }
        }
        
        if(total >= M) {
            result = middle;
            left = middle + 1;
        } else {
            right = middle - 1;
        }
        
    }
    
    cout << result;
    return 0;
}