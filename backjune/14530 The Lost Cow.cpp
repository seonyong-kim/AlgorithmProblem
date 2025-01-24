#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x, y;
	cin >> x >> y;
	int move = 1;
	int answer = 1;
	bool plus = true;
	while (true) {
		if (abs(y-x) > move) {
			answer += move;
			move+=move;
			answer += move;
			plus = !plus;
		}
		if (abs(y - x) <= move){
			if ((plus && y > x) || (!plus && y < x)) {
				answer -= move - abs(y - x);
				break;
			}
			else {
				answer += move;
				move += move;
				answer += move;
				plus = !plus;
			}
		}
	}
	cout << answer;
}
// 10 1
// 10 11(1) 8(4) 14(9) 2(16) 15(25)