#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string N;
	cin >> N;

	for (int i = 0; i < N.size(); i++) {
		if (i == N.size() / 2)
			cout << " ";
		cout << N[i];
	}
}
