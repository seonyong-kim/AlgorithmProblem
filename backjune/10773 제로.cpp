#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k;
	cin >> k;
	stack<int> st;
	while (k--) {
		int n;
		cin >> n;
		if (n != 0)	st.push(n);
		else st.pop();
	}

	int sum = 0;
	int n = st.size();
	for (int i = 0; i < n; i++) {
		sum += st.top();
		st.pop();
	}
	cout << sum;
}
