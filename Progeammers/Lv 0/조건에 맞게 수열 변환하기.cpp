#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    for (int& c : arr) {
        if (c < 50 && c % 2 == 1)  c *= 2;
        else if (c >= 50 && c % 2 == 0)  c /= 2;
    }
    return arr;
}