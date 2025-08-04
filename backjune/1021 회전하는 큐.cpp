#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> vec(M);
	for (int i = 0; i < M; i++) {
		cin >> vec[i];
	}

	int answer = 0;
	while (!vec.empty()) {
		int min = vec[0] - 1;
		int max = (N - vec[0]) + 1;

		// �������� ���� ��찡 �� ���� ���
		if (min <= max) {
			vec.erase(vec.begin()); // ����
			answer += min; // �̵��� Ƚ�� �߰��ϱ�
			for (int i = 0; i < vec.size(); i++) {
				vec[i] -= (min + 1);
				// �������� �̵��ϴٰ� ������ �ȴٸ�
				// ���������� �̵���Ű�� ������ ������ �Ѵ�.
				if (vec[i] < 1) {
					vec[i] += N;
				}
			}
		}
		// ���������� ���� ��찡 �� ���� ���
		else {
			vec.erase(vec.begin());
			answer += max;
			// ������ �Ǵ� ��찡 ������, �ε��� ������ �ʰ��ϴ� ��찡 ���� ����
			for (int i = 0; i < vec.size(); i++) {
				vec[i] = (vec[i] + max - 1) % (vec.size() + 1);
			}
		}
		N--;
	}
	cout << answer;
}

// 10 10
// 1 6 3 2 7 9 8 4 10 5
// 5 2 1 6 8 7 3 9 4 (9)
// 1

//
// 27 6
// 21 11
// 
//
