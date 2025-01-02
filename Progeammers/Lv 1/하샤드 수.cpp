#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int sum = 0;
    int number = x;
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }
    if (x % sum != 0) {
        return false;
    }
    return true;
}