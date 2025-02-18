#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int row = 0;
    int column = 0;
    
    for(int i = 0; i < sizes.size(); i++) {
        if(sizes[i][0] >= sizes[i][1]) {
            row = max(row, sizes[i][0]);
            column = max(column, sizes[i][1]);
        } else {
            row = max(row, sizes[i][1]);
            column = max(column, sizes[i][0]);
        }
        
    }
    answer = row * column;
    // cout << row << " " << column << " " << answer << '\n';
    
    return answer;
}