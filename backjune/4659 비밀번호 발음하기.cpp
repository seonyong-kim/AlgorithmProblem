#include <iostream>
#include <vector>
using namespace std;

bool isMoeum(char c) {
	char moeum[5] = { 'a', 'e', 'i', 'o', 'u' };
	for (char m : moeum) {
		if (c == m)
			return true;
	}
	return false;
}

void check(string answer) {
	bool check = true, check2 = false;

	for (int i = 0; i < answer.size(); i++) {
		// 모음(a,e,i,o,u) 하나를 반드시 포함하여야 한다.
		if (check2 == false) 
			check2 = isMoeum(answer[i]);

		// 같은 글자가 연속적으로 두번 오면 안되나, ee 와 oo는 허용한다.
		if (i != 0 && answer[i - 1] == answer[i]) {
			if (answer[i] == 'e' || answer[i] == 'o') {
				if (answer.size() > i + 1 && answer[i] == answer[i+1]) {
					check = false;
					break;
				}
			}
			else {
				check = false;
				break;
			}
		}

		// 모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
		if (i > 0 && i < answer.size() - 1) {
			if (isMoeum(answer[i - 1]) == isMoeum(answer[i]) && isMoeum(answer[i]) == isMoeum(answer[i + 1])) {
				check = false;
				break;
			}
		}
	}

	if (check && check2) 
		cout << "<" << answer << "> is acceptable.\n";
	else 
		cout << "<" << answer << "> is not acceptable.\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string answer;
	while (true) {
		cin >> answer;
		if (answer == "end") {
			break;
		}

		check(answer);
	}
}