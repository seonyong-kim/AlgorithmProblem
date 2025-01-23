#include <iostream>

using namespace std;

int find(int* arr, int b);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	int* arr = new int[n + 1];
	for (int i = 0; i < n+1; i++) {
		arr[i] = i;
	}
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0) {
			if(find(arr,b) != find(arr,c))
				arr[find(arr, c)] = find(arr, b);
		}
		else if (a == 1) 
			cout << (find(arr, b) == find(arr, c) ? "YES" : "NO") << "\n";
	}

	delete[] arr;
}

int find(int* arr,int b) {
	if (arr[b] != b)
		arr[b] = find(arr, arr[b]);
	return arr[b];
}
// 0 1 2 3 4 5 6 7
// 0 1 4 1 4 5 1 1