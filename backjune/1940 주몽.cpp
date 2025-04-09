#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<int> number(N);

    for(int i=0; i<N; i++)
        cin >> number[i];

    sort(number.begin(), number.end());

    int start = 0, end = number.size() - 1, sum = 0;
    while (start < end) {
        if (number[start] + number[end] == M) {
            sum++;
            start++;
            end--;
        }
        else if(number[start] + number[end] < M)
            start++;
        else 
            end--;
    }
    cout << sum;
}
// 1 2 3 4 5 7 