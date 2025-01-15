#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    sort(d.begin(), d.end());
    int answer = 0;
    for (int i : d) {
        if (budget < i)
            break;
        budget -= i;
        answer++;
    }
    return answer;
}