#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n, int m) {
    int small, big;

    if (m > n) { big = m;  small = n; }
    else { big = n;  small = m; }

    while (small != 0) {
        int temp = small;
        small = big % small;
        big = temp;
    }

    return { big, n * m / big };
}