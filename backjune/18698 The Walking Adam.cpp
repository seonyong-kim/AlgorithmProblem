#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		string str;
		cin >> str;
		int count = 0;
		bool fall = false;
		for (char c : str) {
			if (c == 'U') {
				count++;
			}
			else if (c == 'D') {
				cout << count;
				fall = true;
				break;
			}
		}
		if (!fall)
			cout << count;
		cout << "\n";
	}
}
