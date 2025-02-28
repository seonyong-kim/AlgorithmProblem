#include <iostream>
#include <vector>
using namespace std;

int slidingwindow(vector<int>& vec, int X) {
    int maxLength = 0, i = 0;
    for (int right = 1; right < vec.size(); right++) {
        i = 0;
        int count = 0;
        while (right + i < vec.size() &&vec[right + i] - vec[right + i - 1] <= X) {
            i++;
            count++;
        }
        maxLength = max(maxLength, count);
    }
    return maxLength + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, X;
    cin >> N >> X;
    int A;
    vector<int> vec;
    while (N--) {
        cin >> A;
        vec.emplace_back(A);
    }
    cout << slidingwindow(vec, X);
}
