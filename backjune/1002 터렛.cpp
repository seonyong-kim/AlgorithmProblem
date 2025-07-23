#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int T, x1, y1, r1, x2, y2, r2;
	cin >> T;
	while (T--) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		// �� ����
		// 1. �߽� ���� ��ġ �������� ���� 0 �Ǵ� ���Ѵ�
		// 2. �ܺο��� ���Ѵ�.
		// �������հ� �� �������� ���̿� ���� 0, 1, 2
		// 3. ���ο��� ���Ѵ�.
		// 2,3�� ������ ���� �� ���� ������ ���ϱ�
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
		// �߽��� ���� ���
		if (x1 == x2 && y1 == y2) {
			if (r1 == r2) {
				cout << -1 << '\n';
			}
			else {
				cout << 0 << "\n";
			}
		}
		// ���ο��� ���Ҷ�
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
		// �ܺο��� ���Ҷ�
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