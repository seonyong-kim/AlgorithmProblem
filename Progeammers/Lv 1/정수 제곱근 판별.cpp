#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(long long n) {
    long long number = sqrt(n);
    if (pow(number, 2) == n) {
        return pow(number + 1, 2);
    }
    return -1;
}