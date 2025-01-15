#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n) {
    string result = "";
    while (n != 0) {
        result += n % 3;
        n /= 3;
    }
    int answer = 0;
    for (int i = 0; i < result.size(); i++) {
        answer += pow(3, i) * result[result.size() - 1 - i];
    }
    return answer;
}