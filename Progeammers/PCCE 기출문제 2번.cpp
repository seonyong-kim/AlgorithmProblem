#include <iostream>

using namespace std;

int main(void) {
    int angle1;
    int angle2;
    cin >> angle1 >> angle2;

    int sum_angle = angle1 + angle2;
    cout << sum_angle % 360 << endl; //이부분을 수정
    return 0;
}