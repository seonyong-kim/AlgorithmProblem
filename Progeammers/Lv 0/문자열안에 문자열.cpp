#include <string>
#include <vector>

using namespace std;

int solution(string str1, string str2) {
    auto str = str1.find(str2);
    if (str != string::npos) {
        return 1;
    }
    return 2;
}