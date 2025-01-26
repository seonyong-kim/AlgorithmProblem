#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> vec;
	while (N--) {
		string str;
		cin >> str;
		if (str == "push") {
			int x;
			cin >> x;
			vec.push_back(x);
		}
		else if (str == "pop") {
			if (vec.empty())
				cout << "-1\n";
			else {
				cout << vec[0] << "\n";
				vec.erase(vec.begin());
			}
		}
		else if (str == "size") {
			cout << vec.size() << "\n";
		}
		else if (str == "empty") {
			cout << vec.empty() << "\n";
		}
		else if (str == "front") {
			if (vec.empty())
				cout << "-1\n";
			else 
				cout << vec[0] << "\n";
		}
		else if (str == "back") {
			if (vec.empty())
				cout << "-1\n";
			else
				cout << vec[vec.size() - 1] << "\n";
		}
	}
}