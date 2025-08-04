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

		// 왼쪽으로 가는 경우가 더 빠른 경우
		if (min <= max) {
			vec.erase(vec.begin()); // 삭제
			answer += min; // 이동한 횟수 추가하기
			for (int i = 0; i < vec.size(); i++) {
				vec[i] -= (min + 1);
				// 왼쪽으로 이동하다가 음수가 된다면
				// 오른쪽으로 이동시키고 나머지 연산을 한다.
				if (vec[i] < 1) {
					vec[i] += N;
				}
			}
		}
		// 오른쪽으로 가능 경우가 더 빠른 경우
		else {
			vec.erase(vec.begin());
			answer += max;
			// 음수가 되는 경우가 없지만, 인덱스 범위를 초과하는 경우가 있을 수도
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
