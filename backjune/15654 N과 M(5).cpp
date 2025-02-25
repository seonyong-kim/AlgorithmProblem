#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> path;    
vector<int> answer;   
bool visited[8] = { 0 };   
void backtrack(int* start);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    path.resize(N); 

    for (int i = 0; i < N; i++) 
        cin >> path[i];

    sort(path.begin(), path.end());  
    backtrack(&path[0]); 
}

void backtrack(int* start) {
    if (answer.size() == M) {
        for (int num : answer) {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {  
            visited[i] = true;
            answer.emplace_back(*(start + i));  
            backtrack(start);  
            answer.pop_back(); 
            visited[i] = false; 
        }
    }
}
