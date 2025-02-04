#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, h;
    cin >> N >> M;

    vector<int> tree(N);
    for (int i = 0; i < N; i++) {
        cin >> tree[i];
    }

    sort(tree.begin(), tree.end());

    int start = 0; int end = tree[N - 1]; 
    int mid, result;
    while (start <= end) {
        long long sum = 0;
        mid = (start + end) / 2;
        for (int i : tree) {
            if (i > mid)
                sum += (i - mid);
        }
        if (sum >= M) {
            result = mid;
            start = mid + 1;
        }
        else if (sum < M)
            end = mid - 1;
        else
            break;
    }
    cout << result;
}
