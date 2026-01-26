#include <iostream>
#include <string>

using namespace std;

class Array {
private:
	int* arr;
	int arrSize;
public:
	Array(int sz) {
		this->arrSize = sz;
		this->arr = new int[arrSize];
		for (int i = 0; i < arrSize; i++) {
			arr[i] = 0;
		}
	}

	int at(int index) 
	{
		return arr[index];
	}

	void add(int index, int element) {
		for (int i = arrSize - 2; i >= index; i--) {
			arr[i + 1] = arr[i];
		}
		arr[index] = element;
	}

	void remove(int index) {
		for (int i = index + 1; i < arrSize; i++) {
			arr[i - 1] = arr[i];
		}
	}

	void set(int index, int element) {
		arr[index] = element;
	}

	int count(int element) {
		int count = 0;
		for (int i = 0; i < arrSize; i++) {
			if (arr[i] == element)
				count++;
		}
		return count++;
	}

	void print() {
		for (int i = 0; i < arrSize; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	int T, N;
	string input;
	cin >> T>> N;
	Array array(N);

	while (T--) {
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
		else if (input == "count") {
			int i;
			cin >> i;
			cout << array.count(i) << endl;
		}
		else if (input == "print") {
			array.print();
		}
	}
}
