#include <string>
#include <vector>
using namespace std;

int solution(int a, int b, int n) {
    int count = 0;
    int remainder = 0;
    while (n >= a) {
        remainder = n % a;
        count += (n / a) * b;
        n = (n / a) * b + remainder;
    }
    return count;
}