#include <string>
#include <vector>
#include <iostream>
using namespace std;

string finalWord;
int counter = 0;
int answer = -1;
char arr[5] = { 'A','E', 'I', 'O', 'U' };

void dfs(string word) {
    if (!word.empty()) {
        counter++;
        if (word == finalWord) {
            answer = counter;
            return;
        }
    }

    if (word.size() == 5) return;

    for (int i = 0; i < 5; i++) {
        word.push_back(arr[i]);
        dfs(word);
        if (answer != -1) return;
        word.pop_back();
    }
}

int solution(string word) {
    finalWord = word;
    dfs("");
    return counter;
}