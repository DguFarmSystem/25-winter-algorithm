#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < scoville.size(); i++) {
        pq.push(scoville[i]);
    }
    while(pq.top() < K) {
        if(pq.size() == 1) return -1;
        int one = pq.top();
        pq.pop();
        int two = pq.top();
        pq.pop();
        one = one + two*2;
        pq.push(one);
        answer++;
    }
    return answer;
}