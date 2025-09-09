#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
unordered_set<int> Set;

void permu(string numbers, int start, int c) {
    if (start == c) {  
        int num = stoi(numbers.substr(0, c));
        Set.insert(num);
        return;
    }
    
    for(int i = start; i < numbers.size(); i++) {
        swap(numbers[start], numbers[i]);
        permu(numbers, start + 1, c);
        swap(numbers[start], numbers[i]);
    }
    
}

int solution(string numbers) {
    int answer = 0;
    vector<int> v;
    for(int i = 0; i < numbers.size(); i++) {
        v.push_back(numbers[i]);
    }
    
    // do{
    //     int num = stoi(numbers);
    //     if(!Set.count(num)){
    //         Set.insert(num);
    //     }
    // } while(next_permutation(numbers.begin(), numbers.end()));
    
    for(int i = 1; i <= numbers.size(); i++) {
        permu(numbers, 0, i);
    }
    
    for(int i : Set) {
        // cout << i << '\n';
        bool b = false;
        if(i == 0 || i == 1) continue;
        for(int j = 2; j < i; j++) {
            if(i % j == 0) {
                b = true;
                break;
            }
        }
        if(!b) {
            answer++;
            // cout << i << '\n';
        }
    }
    return answer;
}