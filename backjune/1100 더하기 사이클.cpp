#include <iostream>
using namespace std;

int main() {
    int N, M, count = 0;
    cin >> N;
    M = N;
    do {
        int a = M / 10;
        int b = M % 10;
        int c = (a + b) % 10;
        M = b * 10 + c;
        count++;
    } while (N != M);

    cout << count;
}