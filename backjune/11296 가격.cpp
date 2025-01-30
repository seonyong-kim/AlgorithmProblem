#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

struct object {
    double price;
    char dots;
    char coupon;
    char pay;

    double downprice() {
        switch (this->dots) {
        case 'R':
            this->price *= 0.55;
            break;
        case 'G':
            this->price *= 0.7;
            break;
        case 'B':
            this->price *= 0.8;
            break;
        case 'Y':
            this->price *= 0.85;
            break;
        case 'O':
            this->price *= 0.9;
            break;
        case 'W':
            this->price *= 0.95;
            break;
        }

        if (coupon == 'C') {
            this->price *= 0.95;
        }

        if (pay == 'C') {
            return round(this->price * 10) / 10;
        }
        return round(this->price * 100) / 100;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    object ob;
    while (n--) {
        cin >> ob.price >> ob.dots >> ob.coupon >> ob.pay;
        cout << "$" << std::fixed << std::setprecision(2) << ob.downprice() << "\n";
    }
}