#include <iostream>
using namespace std;

int main() {
	// 단어를 입력받아 저장하기
	string str;
	cin >> str;

	// 문자열을 앞 뒤로 해서 같은지 확인
	int len = str.length();
	int start = 0; 
	int end = len - 1;
	int answer = 1;
	while (start < end) {
		if (str[start] != str[end]) {
			answer = 0;
			break;
		}
		start++;
		end--;
	}

	cout << answer;
}