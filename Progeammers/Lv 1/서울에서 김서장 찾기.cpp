#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    int index = 0;
    for (int i = 0; i < seoul.size(); i++) {
        if (seoul[i] == "Kim") {
            index = i;
            break;
        }
    }
    return "�輭���� " + to_string(index) + "�� �ִ�";
}