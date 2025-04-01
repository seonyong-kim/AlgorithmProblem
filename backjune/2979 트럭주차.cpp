#include <iostream>
#include <vector>
using namespace std;

string str;
int cnt[26];

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	int A, B, C;
	cin >> A >> B >> C;
	vector<int> time(101,0);

	int start, end;
	for (int j = 0; j < 3; j++) {
		cin >> start >> end;
		for (int i = start; i < end; i++) {
			time[i]++;
		}
	}

	int sum = 0;
	for (int i : time) {
		if (i == 3)
			sum += 3 * C;
		else if (i == 2)
			sum += 2 * B;
		else if (i == 1)
			sum += A;
	}

	cout << sum;
}
// 1  2  3  4  5  6  7  
// 1  2  3  3  2  1  1  
// 5 11 14 17 23 