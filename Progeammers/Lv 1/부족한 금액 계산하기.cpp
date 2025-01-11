using namespace std;

long long solution(int price, int money, int count) {
    long long answer = money;
    while (count > 0) {
        answer -= price * count;
        count--;
    }
    return answer >= 0 ? 0 : -answer;
}