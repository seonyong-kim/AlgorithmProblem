#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, j;
    cin >> N >> M >> j;
    vector<int> appleLocation(j);
    for (int i = 0; i < j; i++) {
        cin >> appleLocation[i];
    }
    
    // 왼쪽 포인트와 오른쪽 포인트를 저장해서 
    // 작은 지 큰지에 따라 이동시키면 이동한것을 더해준다.
    int sum = 0;
    int leftPoint = 1;
    int rightPoint = M;

    for (int i : appleLocation) {
        if (i < leftPoint) {
            sum += (leftPoint - i);
            rightPoint += (i - leftPoint);
            leftPoint = i;
        }
        else if (i > rightPoint) {
            sum += (i - rightPoint);
            leftPoint += (i - rightPoint);
            rightPoint = i;
        }
    }
    cout << sum;
}
