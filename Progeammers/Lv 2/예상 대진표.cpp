#include <iostream>

using namespace std;
int nextNumber(int n) {
    if (n % 2 == 0)
        return n / 2;
    else
        return n / 2 + 1;

}
int solution(int n, int a, int b) {
    int big = a;
    int small = b;
    if (a < b) {
        big = b;
        small = a;
    }

    int answer = 1;
    while (small + 1 != big || nextNumber(small) != nextNumber(big)) {
        small = nextNumber(small);
        big = nextNumber(big);
        answer++;
    }
    return answer;
}