#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    for(int i = 0; i < arr.size(); i++) {
        if(answer.empty()) {
            answer.push_back(arr[i]);
            continue;
        }
        if(answer.back() == arr[i]) {
            continue;
        } else {
            answer.push_back(arr[i]);
        }
    }

    return answer;
}