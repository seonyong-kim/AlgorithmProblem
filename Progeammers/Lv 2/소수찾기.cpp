#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

bool isPrime(int n) {
    if (n < 2)
        return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int solution(string numbers) {
    set<int> candidates;
    sort(numbers.begin(), numbers.end());

    do {
        for (int len = 1; len <= numbers.size(); len++) {
            int num = stoi(numbers.substr(0, len));
            candidates.insert(num);
        }
    } while (next_permutation(numbers.begin(), numbers.end()));

    int answer = 0;
    for (int num : candidates) {
        if (isPrime(num))
            answer++;
    }
    return answer;

}
