#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int T, x1, y1, r1, x2, y2, r2;
	cin >> T;
	while (T--) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		// 원 기준
		// 1. 중심 같은 위치 반지름에 따른 0 또는 무한대
		// 2. 외부에서 접한다.
		// 반지름합과 두 원사이의 길이에 따른 0, 1, 2
		// 3. 내부에서 접한다.
		// 2,3번 구별을 위해 더 작은 반지름 구하기
		int small, big;
		if (r1 > r2) {
			small = r2;
			big = r1;
		}
		else {
			small = r1;
			big = r2;
		}
		double length = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
		// 중심이 같은 경우
		if (x1 == x2 && y1 == y2) {
			if (r1 == r2) {
				cout << -1 << '\n';
			}
			else {
				cout << 0 << "\n";
			}
		}
		// 내부에서 접할때
		else if (big > length) {
			if (big > length + small) {
				cout << 0 << "\n";
			}
			else if (big == length + small) {
				cout << 1 << "\n";
			}
			else {
				cout << 2 << "\n";
			}
		}
		// 외부에서 접할때
		else {
			if (length > r1 + r2) {
				cout << 0 << "\n";
			}
			else if (length == r1 + r2) {
				cout << 1 << "\n";
			}
			else {
				cout << 2 << "\n";
			}
		}
	}
}