#include <iostream>
#include <cmath>
using namespace std;

void DFS(int number, int n, int N);
bool isPrime(int number);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	DFS(2,1,N);
	DFS(3,1,N);
	DFS(5,1,N);
	DFS(7,1,N);
}

void DFS(int number, int n,int N) {
	if (n == N) {
		if (isPrime(number)) {
			cout << number << "\n";
		}
		return;
	}
	for (int i = 1; i < 10; i++) {
		if (i % 2 == 0)
			continue;
		if (isPrime(number * 10 + i))
			DFS(number * 10 + i, n+1, N);
	}
}

bool isPrime(int number) {
	for (int i = 2; i <= sqrt(number); i++) {
		if (number % i == 0)
			return false;
	}
	return true;
}