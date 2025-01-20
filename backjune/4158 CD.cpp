#include <iostream>
#define fio cin.tie(0)->sync_with_stdio(0)
using namespace std;

#include <vector>
int main() {
    fio;
    int N, M;
    //
    while (1) {
        cin >> N >> M;
        if (N == 0 && M == 0) break;
        //
        vector<int> SK(N, 0);
        for (int i = 0; i < N; i++)   cin >> SK[i];
        //
        int cnt = 0;
        for (int i = 0; i < M; i++) {
            int tmp; cin >> tmp;
            //
            int left_idx = 0, right_idx = SK.size() - 1;
            while (left_idx <= right_idx) {
                int mid_idx = (left_idx + right_idx) / 2;
                if (SK[mid_idx] == tmp) {
                    cnt++;
                    break;
                }
                else if (SK[mid_idx] > tmp) {
                    right_idx = mid_idx - 1;
                }
                else {
                    left_idx = mid_idx + 1;
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}