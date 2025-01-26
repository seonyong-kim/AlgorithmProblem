#include <iostream>
#include <vector>
using namespace std;

int main() {

	int N, k;
	cin >> N >> k;
	vector<int> vec;
	for (int i=0; i < N; i++) {
		vec.emplace_back(i+1);
	}

	cout << "<";
	int index = k - 1;
	while (true) {
		if (vec.size() == 1) {
			cout << vec[index] << ">";
			break;
		}
		cout << vec[index] << ", ";
		vec.erase(vec.begin() + index);
		index = (index - 1 + k) % vec.size();
	}
}

// 1 2 3 4 5 6 7
//     0
//           0
//   0