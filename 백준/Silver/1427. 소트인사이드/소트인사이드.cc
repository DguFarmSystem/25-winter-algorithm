#include <bits/stdc++.h>
using namespace std;

bool compare(const char& a, const char& b) {
    
    return a > b;
}

int main()
{
    string s;
    cin >> s;
    sort(s.begin(), s.end(), compare);
    
    cout << s;

    return 0;
}