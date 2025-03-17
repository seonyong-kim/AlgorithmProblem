#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

int N, M;
vector<vector<pair<int, int>>> graph;

vector<int> dijkstra(int start) {
    vector<int> dist(N + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // ÃÖ¼Ò Èü

    dist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int current_cost = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();

        if (current_cost > dist[current_node])
            continue;

        for (auto& neighbor : graph[current_node]) {
            int next_node = neighbor.first;
            int weight = neighbor.second;
            int new_cost = current_cost + weight;

            if (new_cost < dist[next_node]) {
                dist[next_node] = new_cost;
                pq.push({ new_cost, next_node });
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    graph.resize(N + 1);

    for (int i = 0; i < M; i++) {
        int start, end, cost;
        cin >> start >> end >> cost;
        graph[start].emplace_back(end, cost);
    }

    int start, end;
    cin >> start >> end;

    vector<int> shortest_paths = dijkstra(start);
    cout << shortest_paths[end];
}

// 1 {2 2} {3 3} {4 1} {5 10}
// 2 {4, 2}
// 3 {4, 1} {5, 1}
// 4 {5, 3}
// 
// 2 2
// 3 3
// 4 1
// 5 4
// 
// 1 2 2
// 1 3 3
// 1 4 1
// 1 5 10
// 2 4 2
// 3 4 1
// 3 5 1
// 4 5 3