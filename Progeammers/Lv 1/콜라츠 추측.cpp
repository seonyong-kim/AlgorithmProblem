#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    long number = num;
    int answer = 0;
    while (number != 1) {
        if (number % 2 == 0) {
            number /= 2;
        }
        else {
            number = number * 3 + 1;
        }
        answer++;
        if (answer >= 500 && number != 1) {
            answer = -1;
            break;
        }
    }
    return answer;
}