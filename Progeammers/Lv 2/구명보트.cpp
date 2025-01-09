#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    int count = 0;   int sum = 0;
    int heavy = 0;    int light = 0;
    while (heavy < people.size() && light < people.size()) {
        sum = people[light] + people[people.size() - heavy - 1];
        if (sum > limit) {
            heavy++;
        }
        else {
            heavy++;
            light++;
        }
        count++;
        if (heavy > people.size() - light - 1) {
            break;
        }
    }
    return count;
}