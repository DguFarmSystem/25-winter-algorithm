#include <iostream>
using namespace std;

int main() {
    int n;
    string numbers;
    cin >> n;         // 숫자의 개수 입력
    cin >> numbers;   // 공백 없이 이어진 숫자 입력

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += numbers[i] - '0';  // 문자형 숫자를 정수로 변환
    }

    cout << sum << endl;

    return 0;
}
