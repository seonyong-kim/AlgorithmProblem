#include <string>
#include <vector>

using namespace std;

int oneCount(int number) {
    int Count = 0;
    while (number != 0) {
        if (number % 2 == 1)
            Count++;
        number /= 2;
    }
    return Count;
}

int solution(int n) {
    int count = oneCount(n);
    int answer = 0;
    while (true) {
        n++;
        if (oneCount(n) == count) {
            answer = n;
            break;
        }
    }
    return answer;
}