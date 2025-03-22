#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num1;
    string num2;
    cin >> num1 >> num2;
    
    for(int i = 2; i >= 0; i--) {
        int t = num2[i] - '0';
        cout << num1 * t << '\n';
    }
    
    int tt = stoi(num2);
    cout << num1 * tt;
    
    return 0;
}