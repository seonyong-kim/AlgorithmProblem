#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int prod = 0;
    for (int i = 0; i < a.size(); i++) {
        prod += a[i] * b[i];
    }
    return prod;
}