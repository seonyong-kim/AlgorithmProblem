#include <iostream>
using namespace std;

int main() {
	int T, N, M;
	cin >> T;
	while (T--) {
		cin >> N >> M;
		// ������ ���� ���� �ƴұ�? -> nCr = nC_(n-r)���� �̿�����
		long long prod = 1;
		long long div = 1;
		int a = N;
		int b = M;
		// N�� M-N ũ�⸦ ��
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