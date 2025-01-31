#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<string> vec(N);
    for (int i = 0; i < N; i++) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());

    string str;
    vector<string> answer;
    for (int i = 0; i < M; i++) {
        cin >> str;
        int leftIndex = 0;  int rightIndex = vec.size() - 1;    int midIndex;
        while (leftIndex <= rightIndex) {
            midIndex = (leftIndex + rightIndex) / 2;
            if (str > vec[midIndex])
                leftIndex = midIndex + 1;
            else if(str < vec[midIndex])
                rightIndex = midIndex - 1;
            else {
                answer.emplace_back(str);
                break;
            }
        }
    }

    sort(answer.begin(), answer.end());

    cout << answer.size() << "\n";
    for (string str : answer) {
        cout << str << "\n";
    }
}