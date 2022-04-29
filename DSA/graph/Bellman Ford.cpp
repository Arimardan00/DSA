#include <bits/stdc++.h>
using namespace std;

struct edge {
    int u, v, wt;
    edge(int first, int second, int third) {
        u = first;
        v = second;
        wt = third;
    }
};

vector<int> bellmanFord(vector<edge> &graph, int src, int n) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    for (int i = 1; i < n; i++) {
        for (auto it : graph) {
            if (dist[it.u] + it.wt < dist[it.v]) {
                dist[it.v] = dist[it.u] + it.wt;
            }
        }
    }

    int flag = 0;
    for (auto it : graph) {
        if (dist[it.u] + it.wt < dist[it.v]) {
            flag = 1;
            cout << "Negative Cycle" << endl;
            break;
        }
    }

    if (!flag) return dist;
    return {};
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<edge> graph(n);
    while (m--) {
        int u, v, wt;
        cin >> u, v, wt;
        graph.push_back(edge(u, v, wt));
    }

    int src = 0;
    vector<int> dist = bellmanFord(graph, src, n);
    if (!dist.empty()) {
        for (int d : dist) cout << d << " ";
    }

    return 0;
}