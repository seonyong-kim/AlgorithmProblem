#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1 - i; j++) {
			cout << " ";
		}
		cout << "*";
		for (int j = 0; j < 2 * i - 1; j++) {
			cout << " ";
		}
		if (i != 0)
			cout << "*";
		cout << "\n";
	}
}
// 0 1 2 3
// 0 1 3 5