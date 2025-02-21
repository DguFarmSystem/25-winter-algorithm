#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> map;
    for(string s : completion) {
        map[s]++;
    }
    for(string s : participant) {
        if(map[s]) {
            map[s]--;
        }
        else {
            answer = s;
            
        }
    }
    return answer;
}