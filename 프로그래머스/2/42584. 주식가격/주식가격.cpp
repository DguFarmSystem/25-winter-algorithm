#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    stack<int> stk;
    
    for(int i = 0; i < prices.size(); i++) {
        while(!stk.empty() && prices[stk.top()] > prices[i]) {
            int index = stk.top();
            stk.pop();
            answer[index] = i - index;
        }
        stk.push(i);
    }
    
    while(!stk.empty()) {
        int idx = stk.top();
        stk.pop();
        answer[idx] = prices.size() - 1 - idx;
    }
    return answer;
}