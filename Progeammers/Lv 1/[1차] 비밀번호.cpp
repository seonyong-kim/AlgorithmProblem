#include <string>
#include <vector>

using namespace std;

vector<bool> change(int n, int N) {
    vector<bool> vec;
    while (n > 0) {
        vec.emplace_back(n % 2);
        n /= 2;
    }
    while (vec.size() < N) {
        vec.emplace_back(0);
    }
    return vec;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for (int i = 0; i < n; i++) {
        vector<bool> vec1 = change(arr1[i], n);
        vector<bool> vec2 = change(arr2[i], n);
        string s = "";
        for (int i = vec1.size() - 1; i >= 0; i--) {
            (vec1[i] || vec2[i]) ? s += "#" : s += " ";
        }
        answer.emplace_back(s);
    }
    return answer;
}