#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> brid;
    for(int i = 0; i < bridge_length; i++) {
        brid.push(0);
    }
    queue<int> q;
    for(int i = 0; i < truck_weights.size(); i++) {
        q.push(truck_weights[i]);
    }
    int t = 0;
    while(!q.empty() || t > 0){
        t -= brid.front();
        brid.pop();
        if(!q.empty()) {
            if(q.front() + t <= weight) {
                int temp = q.front();
                q.pop();
                brid.push(temp);
                t += temp;
            } else {
                brid.push(0);
            }
        } else {
            brid.push(0);
        }
        answer++;
    }
    return answer;
}