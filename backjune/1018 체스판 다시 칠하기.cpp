#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const string patternWhite[8] = {
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW"
};

const string patternBlack[8] = {
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB"
};

int calculateRepaint(const vector<string>& board, int start_x, int start_y) {
	int countWhite = 0;		int countBlack = 0; 
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (board[start_x + i][start_y + j] != patternWhite[i][j]) 
				countWhite++;
			if (board[start_x + i][start_y + j] != patternBlack[i][j]) 
				countBlack++;
		}
	}
	return min(countWhite, countBlack);
}

int main() {
	int N, M;
	cin >> N >> M;
	vector<string> board(N);

	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}

	int minPaint = 64;
	for (int i = 0; i <= N-8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			minPaint = min(minPaint, calculateRepaint(board, i, j));
		}
	}
	cout << minPaint << endl;
}