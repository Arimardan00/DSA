/*
Problem Name: Round Trip 2
Problem Link: https://cses.fi/problemset/task/1678/
Tag: Graph, Cycle Detection in Directed Graph, DFS
Concept: Cycle Detection in Directed Graph
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

bool dfs(int node, vector<bool> &vis, vector<bool> &dfsVis, vector<int> &path, vector<vector<int>> &graph) {
    vis[node] = true;
    dfsVis[node] = true;
    path.push_back(node);
    for (int it : graph[node]) {
        if (!vis[it] && dfs(it, vis, dfsVis, path, graph))
            return true;
        else if (dfsVis[it]) {
            path.push_back(it);
            return true;
        }
    }
    dfsVis[node] = false;
    path.pop_back();
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    vector<bool> vis(n + 1);
    vector<bool> dfsVis(n + 1);
    for (int v = 1; v <= n; v++) {
        vector<int> path;
        if (!vis[v] && dfs(v, vis, dfsVis, path, graph)) {
            int startIndex = find(path.begin(), path.end(), path.back()) - path.begin();
            cout << path.size() - startIndex << endl;
            while (startIndex < path.size()) {
                cout << path[startIndex++] << " ";
            }
            return;
        }
    }
    cout << "IMPOSSIBLE";
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // cin>>t;
    while (t--) {
        solve();
        // cout<<'\n';
    }
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    cerr << fixed << setprecision(10) << "\nTime Taken: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << endl;
#endif

    return 0;
}
