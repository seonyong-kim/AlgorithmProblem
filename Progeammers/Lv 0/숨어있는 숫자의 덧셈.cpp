#include <string>

using namespace std;

int solution(string my_string) {
    int sum = 0;
    for (char c : my_string) {
        if (c >= '0' && c <= '9')
            sum += c - '0';
    }
    return sum;
}