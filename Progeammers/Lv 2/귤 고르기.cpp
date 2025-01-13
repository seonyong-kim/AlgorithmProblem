#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, vector<int> tangerine) {
    sort(tangerine.begin(), tangerine.end());

    vector<int> count;
    for (int i = 0; i < tangerine.size(); i++) {
        if (i == 0 || tangerine[i - 1] != tangerine[i])
            count.emplace_back(1);
        else
            count[count.size() - 1]++;
    }

    sort(count.begin(), count.end(), greater<int>());
    int answer = 0;

    for (int i = 0; i < count.size(); i++) {
        if (k <= 0) break;
        k -= count[i];
        answer++;
    }

    return answer;
}