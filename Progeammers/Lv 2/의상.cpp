#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> m;
    for (int i = 0; i < clothes.size(); i++)  m[clothes[i][1]]++;
    int prod = 1;
    for (auto& p : m)    prod *= (p.second + 1);

    return prod - 1;
}