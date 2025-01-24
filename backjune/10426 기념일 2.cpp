#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string date;
	int n;
	cin >> date >> n;

	int year = stoi(date.substr(0, 4));
	int month = stoi(date.substr(5, 2));
	int day = stoi(date.substr(8, 2));

    vector<int> days_in_month = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    day += n-1; 
    while (true) {
        if (isLeapYear(year)) 
            days_in_month[1] = 29; 
        else 
            days_in_month[1] = 28;

        if (day <= days_in_month[month - 1]) 
            break; 

        day -= days_in_month[month - 1]; 
        month++;

        if (month > 12) { 
            month = 1;
            year++;
        }
    }
    date = to_string(year) + "-" + (month < 10 ? "0" + to_string(month) : to_string(month)) + "-" + (day < 10 ? "0" + to_string(day) : to_string(day));
    cout << date;
}

