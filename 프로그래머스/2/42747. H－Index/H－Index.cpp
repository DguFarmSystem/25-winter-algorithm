#include <bits/stdc++.h>

using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), compare);
    
    for(int i = 0; i < citations.size(); i++) {
        cout << citations[i] << '\n';
        if(citations[i] >= i+1) {
            answer = max(answer, i+1);
        }
    }
    
    return answer;
}