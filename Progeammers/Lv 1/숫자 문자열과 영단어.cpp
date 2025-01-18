#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(string s) {
    int answer = 0;
    map<string, int> mp;
    mp["zero"] = 0; mp["one"] = 1;  mp["two"] = 2; mp["three"] = 3;  mp["four"] = 4;
    mp["five"] = 5; mp["six"] = 6;  mp["seven"] = 7; mp["eight"] = 8; mp["nine"] = 9;
    string tmp = "";

    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9')
            answer = answer * 10 + s[i] - '0';
        else {
            tmp += s[i];
            if (mp.find(tmp) != mp.end()) {
                answer = answer * 10 + mp[tmp];
                tmp.clear();
            }
        }
    }
    return answer;
}