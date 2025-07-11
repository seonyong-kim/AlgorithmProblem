#include <iostream>
using namespace std;

int main(){
	// 입력을 받는다.
	int length;
	cin >> length;

	// 나누기를 통해 나머지 결과가 0 여부에 따라 
	// +1 여부를 결정한다
	if (length % 5 == 0) {
		cout << length / 5;
	}
	else {
		cout << (length / 5) + 1;
	}
}