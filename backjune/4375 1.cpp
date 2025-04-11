#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    while (scanf("%d", &n) != EOF) {
        cin >> n;
        long long number = 1;
        int jarisoo = 1;
        while (true) {
            if (number % n == 0)
                break;
            else {
                number = number * 10 + 1;
                number %= n;
                jarisoo++;
            }
        }
        cout << jarisoo << "\n";
    }
}