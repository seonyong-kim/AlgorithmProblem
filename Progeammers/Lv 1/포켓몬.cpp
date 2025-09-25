#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums) {
    unordered_map<int, int> choice;
    for (int i : nums) {
        choice[i]++;
    }
    if (nums.size() / 2 < choice.size()) {
        return nums.size() / 2;
    }
    return choice.size();
}