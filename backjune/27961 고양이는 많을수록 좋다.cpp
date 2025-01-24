#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long N;
	cin >> N;
	long long  number = 1;
	int count = 1;
	while (N > number) {
		number += number;
		count++;
	}
	if (N == 0)
		count = 0;
	cout << count;
}
// 1000000000000