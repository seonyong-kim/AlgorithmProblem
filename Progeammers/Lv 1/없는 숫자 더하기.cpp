#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    for (int i = 1; i < 10; i++) {
        answer += i;
    }
    for (auto i : numbers) {
        answer -= i;
    }
    return answer;
}