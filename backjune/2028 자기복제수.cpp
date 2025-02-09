#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	int T, N, jarisoo, z;
	cin >> T;
	while (T--) {
		cin >> N;
		jarisoo = to_string(N).size();
		z = pow(10, jarisoo);
		cout << ((N * N) % z == N ? "YES\n" : "NO\n");
	}
}
// 0 1 2 3
// 0 1 3 5