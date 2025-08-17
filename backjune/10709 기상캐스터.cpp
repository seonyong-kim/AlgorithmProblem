#include <iostream>
#include <vector>
using namespace std;

struct cloud{
	char c;
	int t = -1;
};
int H, W;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> H >> W;
	vector<vector<cloud>> m(H, vector<cloud>(W));
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			cin >> m[y][x].c;
			if (m[y][x].c == 'c') {
				m[y][x].t = 0;
				continue;
			}
			if (x > 0 && m[y][x - 1].t != -1)
				m[y][x].t = m[y][x - 1].t + 1;
		}
	}

	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			cout << m[y][x].t << " ";
		}
		cout << "\n";
	}
}