#include <iostream>
using namespace std;

int main(){
	// �Է��� �޴´�.
	int length;
	cin >> length;

	// �����⸦ ���� ������ ����� 0 ���ο� ���� 
	// +1 ���θ� �����Ѵ�
	if (length % 5 == 0) {
		cout << length / 5;
	}
	else {
		cout << (length / 5) + 1;
	}
}