#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    // 패키지와 낱개의 가격의 최솟값을 구한다.
    int minPackagePrice = 1001, minOnePrice = 1001;
    while (M--) {
        int packagePrice, onePrice;
        cin >> packagePrice >> onePrice;
        if (minPackagePrice > packagePrice) {
            minPackagePrice = packagePrice;
        }
        if (minOnePrice > onePrice) {
            minOnePrice = onePrice;
        }
    }

    if (minPackagePrice >= 6 * minOnePrice) {
        cout << minOnePrice * N;
        return 0;
    }

    int package = N / 6;
    int one = N % 6;
    if(minPackagePrice < one * minOnePrice)
        cout << minPackagePrice * (package + 1);
    else
        cout << minPackagePrice * package + minOnePrice * one;
}