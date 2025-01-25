#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		string str;
		getline(cin, str);
		if (str == ".")
			break;

		stack<int> st;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(' || str[i] == '[')
				st.push(str[i]);
			else if (str[i] == ')') {
				if (!st.empty() && st.top() == '(')   st.pop();
				else st.push(str[i]);
			}
			else if (str[i] == ']') {
				if (!st.empty() && st.top() == '[')   st.pop();
				else st.push(str[i]);
			}
		}
		cout << (st.empty() ? "yes\n" : "no\n");

	}
}
