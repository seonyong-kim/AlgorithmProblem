#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string s) {
    int answer = 0;
    if (s[0] == '-') {
        for (int i = 1; i < s.size(); i++) {
            answer += -((s[i] - 48) * pow(10, s.size() - i - 1));
        }
    }
    else if (s[0] == '+') {
        for (int i = 1; i < s.size(); i++) {
            answer += (s[i] - 48) * pow(10, s.size() - i - 1);
        }
    }
    else {
        for (int i = 0; i < s.size(); i++) {
            answer += (s[i] - 48) * pow(10, s.size() - 1 - i);
        }
    }
    return answer;
}
// stoi()함수 쓰면 부호까지 한번에 바꿔준다.
