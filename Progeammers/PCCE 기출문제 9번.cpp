#include <string>
#include <vector>

using namespace std;

bool compare(vector<int> a, vector<int> b) {
    int aLength, bLength;
    if (a[0] > a[1]) {
        if (b[0] > b[1]) {
            if (a[0] >= b[0] && a[1] >= b[1]) {
                return false;
            }
            else {
                return true;
            }
        }
        else {
            if (a[0] >= b[1] && a[1] >= b[0]) {
                return false;
            }
            else {
                return true;
            }
        }
    }
    else {
        if (b[0] > b[1]) {
            if (a[1] >= b[0] && a[0] >= b[1]) {
                return false;
            }
            else {
                return true;
            }
        }
        else {
            if (a[1] >= b[1] && a[0] >= b[0]) {
                return false;
            }
            else {
                return true;
            }
        }
    }
}
int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    while (compare(wallet, bill)) {
        if (bill[0] > bill[1]) {
            bill[0] /= 2;
        }
        else {
            bill[1] /= 2;
        }
        answer++;
    }
    return answer;
}