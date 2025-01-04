#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<int> arr = { 0,1 };
    for (int i = 2; i <= n; i++) {
        arr.emplace_back((arr[i - 1] % 1234567 + arr[i - 2] % 1234567) % 1234567);
    }
    return arr[arr.size() - 1];
}