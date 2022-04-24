/*
Problem Name: Round Trip
Problem Link: https://cses.fi/problemset/task/1669/
Tag: Cycle Detection + DFS
Concept:
    - Use Cycle Detection to find the cycle path
    - Use find method to crop the vector for cycle path
*/
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
#define endl "\n"
#define all(v) v.begin(), v.end()
#define PB push_back
#define MP make_pair
#define ll long long
#define MOD 1000000007
#define clr(val) memset(val, 0, sizeof(val))
#define what_is(x) cout << #x << " is " << x << endl;
#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

bool isCyclic(int node, int parent, vector<bool> &vis, vector<int> &path, vector<vector<int>> &graph) {
    vis[node] = 1;
    path.push_back(node);
    for (int it : graph[node]) {
        if (!vis[it]) {
            if (isCyclic(it, node, vis, path, graph)) return true;
        } else if (it != parent) {
            path.push_back(it);
            return true;
        }
    }
    path.pop_back();
    return false;
}

void detectCycle(vector<vector<int>> &graph, int n) {
    vector<bool> vis(n + 1);
    for (int i = 1; i <= n; i++) {
        vector<int> path;
        if (!vis[i]) {
            if (isCyclic(i, 0, vis, path, graph)) {
                int startIndex = find(path.begin(), path.end(), path.back()) - path.begin();
                cout << path.size() - startIndex << endl;
                while (startIndex < path.size()) cout << path[startIndex++] << " ";
                return;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    detectCycle(graph, n);
    return 0;
}
