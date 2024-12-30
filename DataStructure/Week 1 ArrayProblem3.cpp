#include <iostream>
#include <string>

using namespace std;

class Array {
private:
	int* arr;
	int arrSize;
public:
	Array(int size);
	int at(int index);
	void add(int index, int element);
	void remove(int index);
	void set(int index, int element);
	int sum();
	void print();
};

Array::Array(int size) {
	this->arrSize = size;
	this->arr = new int[arrSize];
	for (int i = 0; i < arrSize; i++) {
		arr[i] = 0;
	}
}

int Array::at(int index) {
	return arr[index];
}

void Array::add(int index, int element) {
	for (int i = arrSize - 2; i >= index; i--) {
		arr[i + 1] = arr[i];
	}
	arr[index] = element;
}

void Array::remove(int index) {
	for (int i = index + 1; i < arrSize; i++) {
		arr[i - 1] = arr[i];
	}
}

void Array::set(int index, int element) {
	arr[index] = element;
}

int Array::sum() {
	int sum = 0;
	for (int i = 0; i < arrSize; i++) {
		sum += arr[i];
	}
	return sum;
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
	while (T--)
	{
		cin >> input;
		if (input == "at") {
			int i;
			cin >> i;
			cout << array.at(i) << endl;
		}
		else if (input == "add") {
			int i, z;
			cin >> i >> z;
			array.add(i, z);
		}
		else if (input == "remove") {
			int i;
			cin >> i;
			array.remove(i);
		}
		else if (input == "set") {
			int i, z;
			cin >> i >> z;
			array.set(i, z);
		}
		else if (input == "sum") {
			cout << array.sum() << endl;
		}
		else if (input == "print") {
			array.print();
		}
	}

}