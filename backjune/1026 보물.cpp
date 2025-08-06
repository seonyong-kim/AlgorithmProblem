#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    
    // DP �������� �ִ� * �ּ� �̷����� ����?
    // �ϴ� ���ĺ���
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int answer = 0;
    for (int i = 0; i < N; i++) {
        answer += (A[i] * B[B.size() - 1 - i]);
    }

    cout << answer;
}