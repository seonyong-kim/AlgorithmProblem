#include <iostream>
using namespace std;

int main() {
	// �ܾ �Է¹޾� �����ϱ�
	string str;
	cin >> str;

	// ���ڿ��� �� �ڷ� �ؼ� ������ Ȯ��
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