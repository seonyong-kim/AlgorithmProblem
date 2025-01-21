#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int A, B;
		cin >> A >> B;
		int small, big;
		if (A > B) {
			small = B; big = A;
		}
		else {
			small = A; big = B;
		}
		while (big % small != 0) {
			int temp = small;
			small = big % small;
			big = temp;
		}
		cout << A * B / small << "\n";
	}
}