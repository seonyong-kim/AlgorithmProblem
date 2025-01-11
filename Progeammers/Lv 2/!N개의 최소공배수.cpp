#include <string>
#include <vector>
using namespace std;

int getGdc(int big, int small) {
    while (small != 0) {
        int temp = small;
        small = big % small;
        big = temp;
    }
    return big;
}

int solution(vector<int> arr) {
    int prod = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        int gdc = getGdc(prod, arr[i]);
        prod = prod * (arr[i] / gdc);
    }
    return prod;
}