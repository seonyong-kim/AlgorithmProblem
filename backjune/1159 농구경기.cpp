#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<char> firstName(26);
	string name;
	for (int i = 0; i < N; i++) {
		cin >> name;
		firstName[name[0] - 'a']++;
	}
	
	string answer = "";
	for (int i = 0; i < 26; i++) {
		if (firstName[i] >= 5) {
			answer += (char)('a' + i);
		}
	}

	cout << (answer.empty() ? "PREDAJA" : answer);
}