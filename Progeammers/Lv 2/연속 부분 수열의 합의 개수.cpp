#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    set<int> s1;
    int n = elements.size();
    for (int j = 0; j < n; j++) {
        int sum = 0;
        for (int i = j; i < n + j; i++) {
            sum += elements[i];
            s1.insert(sum);
        }
        elements.emplace_back(elements[j]);
    }
    return s1.size();
}