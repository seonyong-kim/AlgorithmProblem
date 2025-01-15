#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    for (int i = 0; i <= discount.size() - 10; i++) {
        bool result = true;
        for (int j = 0; j < want.size(); j++) {
            if (count(discount.begin() + i, discount.begin() + i + 10, want[j]) < number[j]) {
                result = false;
                break;
            }
        }
        if (result)  answer++;
    }
    return answer;
}