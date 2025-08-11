#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string change(string str) {
	string s = str;
	for (char c : str) {
		if (c == '0')
			s.erase(s.begin());
		else 
			break;
	}

	if (s == "") {
		return "0";
	}
	return s;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<string> answer;
	string str;
	while (N--) {
		cin >> str;
		string s = "";
		for (int i = 0; i < str.size(); i++) {
			if (str[i] >= '0' && str[i] <= '9') {
				s += str[i];
			}
			else {
				if(s != "")
					answer.push_back(change(s));
				s = "";
			}
		}
		if (s != "") {
			answer.push_back(change(s));
		}
	}

	sort(answer.begin(), answer.end(), [](string& a, string& b){
		if (a.size() != b.size()) return a.size() < b.size();
		return a < b;
	});

	for (string s : answer) {
		cout << s << "\n";
	}
}