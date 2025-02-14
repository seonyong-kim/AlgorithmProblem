#include <iostream>
#include <vector>

using namespace std;

int d_x[3] = { 0,1,1 };
int d_y[3] = { 1,0,1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int R, C, count;
    cin >> R >> C;
    vector<vector<char>> vec(R, vector<char>(C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> vec[i][j];
        }
    }

    bool result = true;
    vector<int> answer(5);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (vec[i][j] == '.' && j < C-1 && i < R-1) {
                result = true;
                count = 0;
                for (int a = 0; a < 3; a++) {
                    int nx = j + d_x[a];
                    int ny = i + d_y[a];
                    if (nx < C && ny < R && vec[ny][nx] == 'X')
                        count++;
                    else if (nx < C && ny < R && vec[ny][nx] == '#') {
                        result = false;
                        break;
                    }
                }
                if (result) 
                    answer[count]++;
            }
            else if (vec[i][j] == 'X' && j < C - 1 && i < R - 1) {
                result = true;
                count = 1;
                for (int a = 0; a < 3; a++) {
                    int nx = j + d_x[a];
                    int ny = i + d_y[a];
                    if (nx < C && ny < R && vec[ny][nx] == 'X')
                        count++;
                    else if (nx < C && ny < R && vec[ny][nx] == '#') {
                        result = false;
                        break;
                    }
                }
                if (result) 
                    answer[count]++;
            }
        }
    }
    for (int i : answer)
        cout << i << "\n";
}