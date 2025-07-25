#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// �༺ ���� ������ ���� ����ü
struct planet {
	int x;
	int y;
	int r;
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, x1, x2, y1, y2, n;
	cin >> T;
	while (T--) {
		cin >> x1 >> y1 >> x2 >> y2 >> n;
		vector<planet> p;
		planet pla;
		while (n--){
			cin >> pla.x >> pla.y >> pla.r;
			p.push_back(pla);
		}

		int answer = 0;
		for (auto i : p) {
			int diff1 = pow(i.x - x1, 2) + pow(i.y - y1, 2);
			int diff2 = pow(i.x - x2, 2) + pow(i.y - y2, 2);
			int length = pow(i.r, 2);
			// �� ���� �� ���� Ȥ�� ��迡 �ִ��� Ȯ�� -> answer 1ȸ �߰�
			if (diff1 > length && diff2 < length || diff2 > length && diff1 < length || diff1 == length || diff2 == length) {
				answer++;
			}
		}
		cout << answer << "\n";
	}
}