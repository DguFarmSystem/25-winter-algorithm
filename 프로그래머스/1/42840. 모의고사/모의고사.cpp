#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> one = {1, 2, 3, 4, 5};
    vector<int> two = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> three = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int ans_one = 0, ans_two = 0, ans_three = 0;
    int s = answers.size();
    for(int i = 0; i < s; i++) {
        if(answers[i] == one[i % 5]) ans_one++;
        if(answers[i] == two[i % 8]) ans_two++;
        if(answers[i] == three[i % 10]) ans_three++;
    }
    vector<pair<int, int>> v;
    v.push_back({ans_one, 1});
    v.push_back({ans_two, 2});
    v.push_back({ans_three, 3});
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    int Max = 0;
    for(int i = 0; i < 2; i++) {
        if(answer.empty()) {
            answer.push_back(v[i].second);
            Max = max(Max, v[i].first);
        }
        if(Max == v[i+1].first) {
            answer.push_back(v[i+1].second);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}