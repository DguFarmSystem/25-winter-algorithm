#include <bits/stdc++.h>
using namespace std;

int Max = INT_MIN;
int Min = INT_MAX;

void permu(vector<int> v, vector<char> o, int start) {
    if (start == o.size()) {
        int num = v[0];
        for (int i = 1; i < v.size(); i++) {
            if (o[i - 1] == '+') num += v[i];
            else if (o[i - 1] == '-') num -= v[i];
            else if (o[i - 1] == '*') num *= v[i];
            else if (o[i - 1] == '/') num /= v[i];
        }
        Max = max(Max, num);
        Min = min(Min, num);
        return;
    }
    for(int i = start; i < o.size(); i++) {
        swap(o[start], o[i]);
        permu(v, o, start+1);
        swap(o[start], o[i]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    vector<int> v;
    int num;
    for(int i = 0; i < N; i++) {
        cin >> num;
        v.push_back(num);
    }
    int opr;
    vector<char> o;
    for(int i = 0; i < 4; i++) {
        cin >> opr;
        for(int j = 0; j < opr; j++) {
            if(i == 0) {
                o.push_back('+');
            }
            else if(i == 1) {
                o.push_back('-');
            }
            else if(i == 2) {
                o.push_back('*');
            }
            else if(i == 3) {
                o.push_back('/');
            }
        }
    }
    // for(char c : o) cout << c << " ";
    // cout << '\n';
    
    permu(v, o, 0);

    cout << Max << '\n';
    cout << Min << '\n';
    return 0;
}