#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int index = 0;
    
    while(index < progresses.size()) {
        for(int i = 0; i < progresses.size(); i++) {
            progresses[i] += speeds[i];
        }
        int t = 0;
        while(progresses[index] >= 100 && index < progresses.size()) {
            t++;
            index++;
            // cout << "안녕" << '\n';
        }
        if(t != 0) answer.push_back(t);
    }
    
    return answer;
}