#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string name;
    cin >> name;

    vector<char> alpabet(26);
    for (char c : name) {
        alpabet[c - 'A']++;
    }

    int oddNumber = 0;
    char oddalphabet = ' ';
    string answer = "";
    for (int i = 25; i >= 0; i--) {
        if (alpabet[i] & 1) {
            oddNumber++;
            oddalphabet = 'A' + i;
            alpabet[i]--;
        }

        if (oddNumber > 1)
            break;


        for (int j = 1; j <= alpabet[i] / 2; j++) {
            answer = char('A' + i) + answer;
            answer += char('A' + i);
        }
    }
    if (oddNumber > 1) {
        cout << "I'm Sorry Hansoo";
        return 0;
    }

    if(oddalphabet != ' ')
        answer.insert(answer.begin() + answer.size() / 2, oddalphabet);
    for (char c : answer) {
        cout << c;
    }
}
// AABBCC 