#include <iostream>
using namespace std;

int main() {
	int N, S;
	while (cin >> N >> S) {
		N++;
		cout << S / N << "\n";
	}
}