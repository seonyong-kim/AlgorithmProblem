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
    
    // ���� ����Ʈ�� ������ ����Ʈ�� �����ؼ� 
    // ���� �� ū���� ���� �̵���Ű�� �̵��Ѱ��� �����ش�.
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
