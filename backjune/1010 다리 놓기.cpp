#include <iostream>
using namespace std;

int main() {
	int T, N, M;
	cin >> T;
	while (T--) {
		cin >> N >> M;
		// 조합을 쓰는 문제 아닐까? -> nCr = nC_(n-r)임을 이용하자
		long long prod = 1;
		long long div = 1;
		int a = N;
		int b = M;
		// N과 M-N 크기를 비교
		if ((M - N) > N) {
			for (int i = 0; i < a; i++) {
				prod *= M;
				div *= N;
				M--;
				N--;
			}
		}
		else { // N > (M-N) 
			for (int i = 0; i < (b - a); i++) {
				prod *= M;
				div *= (M - N);
				M--;
			}
		}
		cout << prod / div << "\n";
	}
}