#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n) {
    int number = floor(sqrt(n));
    if (pow(number, 2) == n)
        return 1;
    return 2;
}