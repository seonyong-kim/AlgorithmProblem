#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = n / 7;
    return n % 7 == 0 ? answer : answer + 1;
}