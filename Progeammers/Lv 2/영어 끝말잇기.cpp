#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer = { 1,1 };
    while (true) {
        for (int i = 0; i < words.size(); i++) {

            if (i != 0 && (words[i - 1][words[i - 1].size() - 1] != words[i][0]) ||
                count(words.begin(), words.begin() + i + 1, words[i]) > 1)
                return answer;

            if (answer[0] >= n) {
                answer[0] = 1;
                answer[1]++;
            }
            else
                answer[0]++;

            if (i == words.size() - 1)
                return { 0,0 };
        }
    }
}