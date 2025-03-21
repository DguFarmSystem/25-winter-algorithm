#include <bits/stdc++.h>
using namespace std;

long long mod_pow(long long a, long long b, long long c) {
    if(b == 0) return 1;
    long long half = mod_pow(a, b/2, c);
    long long result = (half * half) % c;
    if(b % 2 == 1) result = (result * a) % c;
    return result;
}

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    
    cout << mod_pow(A, B, C);

    return 0;
}