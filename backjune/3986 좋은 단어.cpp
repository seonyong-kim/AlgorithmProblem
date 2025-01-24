#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, count = 0;;
	cin >> N;
	while (N--) {
		string str;
		cin >> str;
		stack<int> st;
		for (int i = 0; i < str.size(); i++) {
			if (!st.empty() && str[i] == st.top())
				st.pop();
			else
				st.push(str[i]);
		}
		if (st.empty()) {
			count++;
		}
	}
	cout << count;
}

// 좋은 단어 기준 
// 기본은 개수가 짝수
// 나란히 나오거나 
// LIFO 자료구조