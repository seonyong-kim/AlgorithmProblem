#include <iostream>
using namespace std;

int main() {
	int sum = 0;
	int count;
	for (int i = 0; i < 6; i++) {
		cin >> count;
		sum += count;
	}
	cout << sum * 5;
}