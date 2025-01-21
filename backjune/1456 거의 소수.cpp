#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    long long A, B;
    cin >> A >> B;

    long long limit = sqrt(B);
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false; 

    for (long long i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            for (long long j = i * i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }

    vector<long long> primes;
    for (long long i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }

    int count = 0;
    for (long long prime : primes) {
        long long power = prime * prime; 
        while (power <= B) {
            if (power >= A) {
                count++;
            }
            if (power > B / prime) {
                break;
            }
            power *= prime;
        }
    }

    cout << count;
    return 0;
}
