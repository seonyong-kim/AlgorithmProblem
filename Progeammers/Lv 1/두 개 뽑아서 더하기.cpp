#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            int sum = numbers[i] + numbers[j];
            if (count(answer.begin(), answer.end(), sum) == 0)
                answer.emplace_back(sum);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}