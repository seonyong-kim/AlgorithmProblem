#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int cards1Index = 0, cards2Index = 0, goalIndex = 0;

    while (goalIndex < goal.size()) {
        if (cards1Index < cards1.size() && goal[goalIndex] == cards1[cards1Index])
            cards1Index++;
        else if (cards2Index < cards2.size() && goal[goalIndex] == cards2[cards2Index])
            cards2Index++;
        else
            return "No";
        goalIndex++;
    }

    return "Yes";
}
