#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int length(vector<int>& nums);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> fruit(N);
    for (int i = 0; i < N; i++) {
        cin >> fruit[i];
    }

    cout << length(fruit);
}

int length(vector<int>& nums) {
    int left = 0, max = 0;
    unordered_map<int, int>m;
    for (int right = 0; right < nums.size(); right++) {
        m[nums[right]]++;
        while (m.size() > 2) {
            m[nums[left]]--;
            if (m[nums[left]] == 0)
                m.erase(nums[left]);
            left++;
        }
        max = (max < right - left + 1 ? right - left + 1 : max);
    }
    return max;
}