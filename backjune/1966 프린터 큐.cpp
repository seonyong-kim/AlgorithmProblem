#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N, number, document, importance;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> number >> document;

        queue<pair<int, int>> q;
        priority_queue<int> pq; 
        for (int j = 0; j < number; ++j) {
            cin >> importance;
            q.push({ j, importance });
            pq.push(importance);
        }

        int count = 0;
        while (!q.empty()) {
            int index = q.front().first;
            int value = q.front().second;
            q.pop();
            if (pq.top() == value) {
                pq.pop();
                ++count;
                if (index == document) {
                    cout << count << endl;
                    break;
                }
            }
            else q.push({ index,value });
        }
    }
}