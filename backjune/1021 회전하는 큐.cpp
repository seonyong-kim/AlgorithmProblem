#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    deque<int> dq;
    for (int i = 1; i <= N; i++) {
        dq.push_back(i);
    }

    int ans = 0;
    for (int i = 0; i < M; i++) {
        int target;
        cin >> target;
        // 현재 큐에서 target이 있는 위치를 찾는다.
        int idx = 0;
        for (int x : dq) {
            if (x == target) break;
            idx++;
        }
        // 왼쪽 회전 횟수 = idx
        // 오른쪽 회전 횟수 = dq.size() - idx
        if (idx <= (int)dq.size() - idx) {
            // 왼쪽으로 idx번 회전
            ans += idx;
            while (idx--) {
                int front = dq.front();
                dq.pop_front();
                dq.push_back(front);
            }
        }
        else {
            // 오른쪽으로 (size-idx)번 회전
            int cnt = dq.size() - idx;
            ans += cnt;
            while (cnt--) {
                int back = dq.back();
                dq.pop_back();
                dq.push_front(back);
            }
        }
        // 이제 앞(front)에 target이 오므로 pop
        dq.pop_front();
    }

    cout << ans << "\n";
    return 0;
}


//
// 27 6
// 21 11
// 
//

