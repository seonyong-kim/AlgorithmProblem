#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int max1 = 0, max2 = 0;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] > max1) {
            max2 = max1;
            max1 = numbers[i];
        }
        else if (numbers[i] > max2) {
            max2 = numbers[i];
        }
    }
    int answer = max1 * max2;
    return answer;
}