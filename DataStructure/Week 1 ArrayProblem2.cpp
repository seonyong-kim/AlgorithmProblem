#include <iostream>
#include <string>

using namespace std;
class Array {
private:
	int arrSize;
	int* arr;
public:
	Array(int size);
	void shift(int leftIndex, int rightIndex);
	void swap(int leftIndex, int rightIndex);
	void print();
};

Array::Array(int size) {
	this->arrSize = size;
	this->arr = new int[arrSize];
	for (int i = 0; i < arrSize; i++) {
		arr[i] = i;
	}
}
void Array::shift(int leftIndex, int rightIndex) {
	int saveValue = arr[rightIndex];
	for (int i = rightIndex - 1; i >= leftIndex; i--) {
		arr[i + 1] = arr[i];
	}
	arr[leftIndex] = saveValue;
}
void Array::swap(int leftIndex, int rightIndex) {
	int saveValue = arr[rightIndex];
	arr[rightIndex] = arr[leftIndex];
	arr[leftIndex] = saveValue;
}
void Array::print() {
	for (int i = 0; i < arrSize; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int T, N;
	cin >> T >> N;
	Array array(N);
	string input;

	while (T--) {
		cin >> input;
		if (input == "shift") {
			int i, j;
			cin >> i >> j;
			array.shift(i, j);
		}
		else if (input == "swap") {
			int i, j;
			cin >> i >> j;
			array.swap(i, j);
		}
		else if (input == "print") {
			array.print();
		}
	}
}