#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	long long n;
	cin >> n;
	long long answer = n;
	for (long i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			answer -= answer / i;
			while (n % i == 0) {
				n /= i;
			}
		}
	}
	// n이 소수일때
	if (n > 1) {
		answer -= answer / n;
	}
	cout << answer;
}