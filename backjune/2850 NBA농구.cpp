#include <iostream>
#include <string>
using namespace std;

struct game {
	int team1Score = 0;
	int team2Score = 0;
	int team1WinTime = 0;
	int team2WinTime = 0;
	int sumTime = 0;

	void compare(string time) {
		int pos = time.find(':');
		int m = stoi(time.substr(0, pos));
		int s = stoi(time.substr(pos + 1));
		int t = m * 60 + s;
		if (team1Score > team2Score) {
			team1WinTime += t - sumTime;
		}
		else if (team1Score < team2Score) {
			team2WinTime += t - sumTime;
		}
		sumTime = t;
	}

	void print() {
		int m1 = team1WinTime / 60;
		int s1 = team1WinTime % 60;
		int m2 = team2WinTime / 60;
		int s2 = team2WinTime % 60;

		cout << (m1 < 10 ? "0" : "") << m1 << ":" << (s1 < 10 ? "0" : "") << s1 << "\n"
			<< (m2 < 10 ? "0" : "") << m2 << ":" << (s2 < 10 ? "0" : "") << s2;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, team;
	string time;
	cin >> N;
	game g;
	while (N--) {
		cin >> team >> time;
		g.compare(time);
		if (team == 1) {
			g.team1Score++;
		}
		else {
			g.team2Score++;
		}

	}
	g.compare("48:00");
	g.print();
}
