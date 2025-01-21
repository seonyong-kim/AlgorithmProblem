#include <iostream>
#include <vector>
using namespace std;

int main() {
	int M, N;
	cin >> M >> N;

	vector<bool> vec(N+1, true);
	vec[0] = false;   
	vec[1] = false;

	for (int i = 2; i*i <= N; i++) {
		if (vec[i]) {
			for (int j = i * i; j <= N; j += i) {
				vec[j] = false;
			}
		}
	}

	for (int i = M; i <= N; i++) {
		if (vec[i])
			cout << i << "\n";
	}
}
