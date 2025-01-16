#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    for (long long i = left; i <= right; i++) {
        i% n <= i / n ? answer.emplace_back(i / n + 1) : answer.emplace_back(i % n + 1);
    }

    return answer;
}
