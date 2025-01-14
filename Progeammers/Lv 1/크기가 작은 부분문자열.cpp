#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int size = p.size();
    for (int i = 0; i < t.size() - size + 1; i++) {
        string str = t.substr(i, size);
        if (str <= p) answer++;
    }
    return answer;
}