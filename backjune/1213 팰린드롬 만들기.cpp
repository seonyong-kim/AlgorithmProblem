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
    for (int i = 0; i < name.size(); i++) {
        alpabet[name[i] - 'A']++;
    }

    int oddNumber = 0;
    char oddalphabet = ' ';
    vector<char> answer;
    for (int i = 25; i >= 0; i--) {
        if (alpabet[i] > 0 && alpabet[i] % 2 == 0) {
            for (int j = 1; j <= alpabet[i] / 2; j++) {
                answer.insert(answer.begin(), 'A' + i);
                answer.push_back('A' + i);
            }
        }
        else if(alpabet[i] % 2 == 1) {
            oddNumber++;
            if (oddNumber >= 2) {
                cout << "I'm Sorry Hansoo";
                return 0;
            }
            oddalphabet = 'A' + i;
            if (alpabet[i] > 2) {
                for (int j = 1; j <= alpabet[i] / 2; j++) {
                    answer.insert(answer.begin(), 'A' + i);
                    answer.push_back('A' + i);
                }
            }
        }
    }
    if(oddalphabet != ' ')
        answer.insert(answer.begin() + answer.size() / 2, oddalphabet);

    for (char c : answer) {
        cout << c;
    }
}
// AABBCC 