#include <bits/stdc++.h>
using namespace std;

int Max = INT_MIN;
int Min = INT_MAX;

int main()
{
    int N;
    cin >> N;
    
    int num;
    for(int i = 0; i < N; i++) {
        cin >> num;
        Max = max(Max, num);
        Min = min(Min, num);
    }
    
    cout << Min << " " << Max;

    return 0;
}