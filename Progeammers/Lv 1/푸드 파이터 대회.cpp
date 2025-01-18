#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    int index = 0;

    for (int i = 0; i < food.size(); i++) {
        for (int j = 0; j < (food[i] / 2) * 2; j++) {
            answer.insert(index, to_string(i));
        }
        index += food[i] / 2;
    }
    answer.insert(index, "0");

    return answer;
}