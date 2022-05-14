#include <bits/stdc++.h>
using namespace std;

class UnionFind {
   public:
    vector<int> parent;
    vector<int> rank;
    int count;

    UnionFind(int n) {
        parent = vector<int>(n);
        rank = vector<int>(n);
        count = n;
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int findPar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findPar(parent[node]);
    }

    void unionNodes(int x, int y) {
        x = parent[x];
        y = parent[y];
        if (x == y) return;
        if (rank[x] > rank[y]) {
            parent[y] = x;
        } else {
            parent[x] = y;
            if (rank[x] == rank[y]) rank[y]++;
        }
        count--;
    }

    int getCount() {
        return count;
    }
};
