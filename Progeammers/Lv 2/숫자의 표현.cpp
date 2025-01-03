#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int start = 1;
    int sum = 0;

    for (int end = 1; end <= n; end++) {
        sum += end;

        while (sum > n) {
            sum -= start;
            start++;
        }

        if (sum == n) {
            answer++;
        }
    }

    return answer;
}