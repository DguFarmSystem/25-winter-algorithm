#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown + yellow;
    vector<pair<int, int>> v;
    
    int bb = 0;
    for(int i = 3; i < sum/2; i++) {
        if(sum % i == 0) {
            bb = sum / i;
            v.push_back({i, bb});
            cout << i << " " << bb << '\n';
        }
    }
    int row;
    int column;
    for(auto i : v) {
        row = i.first - 2;
        column = i.second - 2;
        if(row*column == yellow) {
            if(row >= column) {
                answer.push_back(i.first);
                answer.push_back(i.second);
            }
        }
        if(answer.size() == 2) break;
    }
    return answer;
}