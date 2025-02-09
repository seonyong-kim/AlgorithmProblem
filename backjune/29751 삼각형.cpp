#include <iostream>
#include<iomanip>
using namespace std;

int main() {
	double H, W;
	cin >> W >> H;
	cout << fixed << setprecision(1) << W * H * 0.5;
}