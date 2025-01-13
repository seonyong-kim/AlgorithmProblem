#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    for (int i = 0; i < arr.size(); i++) {
        answer.emplace_back(arr[i]);
        int j = 1;
        while (arr[i] == arr[i + j])
            j++;
        i += j - 1;
    }
    return answer;
}