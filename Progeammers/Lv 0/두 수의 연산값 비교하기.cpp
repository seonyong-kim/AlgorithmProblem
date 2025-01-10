#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int a, int b) {
    string c = to_string(b);
    int n = c.length();
    int number1 = a * pow(10, n) + b;
    int number2 = 2 * a * b;
    return number1 > number2 ? number1 : number2;
}