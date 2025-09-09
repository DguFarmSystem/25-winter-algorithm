#include <bits/stdc++.h>

using namespace std;
int Max = 0;

bool compare(int a, int b) {
    string sa = to_string(a);
    string sb = to_string(b);
    
    if(sa + sb > sb + sa) {
        return true;
    } else {
        return false;
    }
}

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), compare);
    for(int i : numbers) {
        answer += to_string(i);
    }
    
    if(answer[0] == '0') return "0";
    return answer;
}