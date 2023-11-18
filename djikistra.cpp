#include <iostream>
#include <vector>
#include <set>
#include <climits>
using namespace std;

void dijkstra(vector<pair<int, int>> graph[], int n, int start, int end) {
    vector<int> distance(n, INT_MAX);
    vector<int> path(n, -1); // To store the path

    distance[start] = 0;
    set<pair<int, int>> s;
    s.insert({0, start});

    while (!s.empty()) {
        int node = s.begin()->second;
        int cost = s.begin()->first;
        s.erase(s.begin());

        if (node == end) {
            cout << "Cost of the shortest path is: " << cost << endl;
            break;
        }

        if (cost != distance[node])
            continue;

        for (auto x : graph[node]) {
            if (distance[node] + x.second < distance[x.first]) {
                distance[x.first] = distance[node] + x.second;
                s.insert({distance[x.first], x.first});
                path[x.first] = node; // Update path to this node
            }
        }
    }

    cout << "Path of the lowest cost: ";
    vector<int> pathNodes;
    for (int node = end; node != -1; node = path[node]) {
        pathNodes.push_back(node);
    }
    if (distance[end] != INT_MAX) {
        for (int i = pathNodes.size() - 1; i >= 0; --i) {
            cout << pathNodes[i] << " ";
        }
    } else {
        cout << "No path found.";
    }
    cout << endl;
}

int main() {
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<pair<int, int>> graph[n];

    cout << "Enter the edges (node1, node2, cost):" << endl;
    for (int i = 0; i < m; i++) {
        int node1, node2, cost;
        cin >> node1 >> node2 >> cost;
        graph[node1].push_back({node2, cost});
        graph[node2].push_back({node1, cost});
    }

    int start, end;
    cout << "Enter the starting node: ";
    cin >> start;
    cout << "Enter the ending node: ";
    cin >> end;

    dijkstra(graph, n, start, end);

    return 0;
}
