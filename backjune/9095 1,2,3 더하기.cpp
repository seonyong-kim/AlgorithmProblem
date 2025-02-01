#include <iostream>

using namespace std;

int combination(int a, int b, int c);
int factorial(int a);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, number, count;
    cin >> n;
    while (n--) {
        count = 0;
        cin >> number;
        int three = number / 3;
        while (true) {
            int a = number - three * 3;
            int two = a / 2;
            while (true) {
                count += combination(three, two, number - three * 3 - two * 2);
                two--;
                if (two < 0)
                    break;
            }
            three--;
            if (three < 0)
                break;
        }
        cout << count << "\n";
    }
}

int combination(int a, int b, int c) {
    return factorial(a + b + c) / (factorial(a)* factorial(b)* factorial(c));
}

int factorial(int a) {
    if (a == 1 || a == 0)
        return 1;
    return a * factorial(a - 1);
}