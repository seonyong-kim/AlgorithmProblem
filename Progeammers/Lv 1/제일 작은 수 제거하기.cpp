#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

vector<int> solution(vector<int> arr) {
    int min = INT_MAX;
    int index;
    for (int i = 0; i < arr.size(); i++) {
        if (min > arr[i]) {
            min = arr[i];
            index = i;
        }
        if (i == arr.size() - 1) {
            arr.erase(arr.begin() + index);
        }
    }
    if (arr.empty()) {
        arr.emplace_back(-1);
    }
    return arr;
}