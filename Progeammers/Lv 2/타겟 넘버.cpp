#include <string>
#include <vector>

using namespace std;

int dfs(int sum, int target, int index, vector<int> numbers) {
    if (index == numbers.size()) {
        return (sum == target) ? 1 : 0;
    }

    return dfs(sum + numbers[index], target, index + 1, numbers)
        + dfs(sum - numbers[index], target, index + 1, numbers);
}

int solution(vector<int> numbers, int target) {
    return dfs(0, target, 0, numbers);
}