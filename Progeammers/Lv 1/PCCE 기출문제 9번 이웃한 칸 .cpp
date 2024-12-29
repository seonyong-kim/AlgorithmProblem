#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    if (h > 0 && board[h][w] == board[h - 1][w]) {
        answer++;
    }
    if (w > 0 && board[h][w] == board[h][w - 1]) {
        answer++;
    }
    if (h < board.size() - 1 && board[h][w] == board[h + 1][w]) {
        answer++;
    }
    if (w < board.size() - 1 && board[h][w] == board[h][w + 1]) {
        answer++;
    }
    return answer;
}