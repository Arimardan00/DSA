/*
Problem Name: Most Stones Removed with Same Row or Column
Problem Link: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
Tag: Disjoint Set
Concept: Use disjoint set with stones index
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    class UnionFind {
       public:
        vector<int> parent;
        int count;

        UnionFind(int n) {
            parent = vector<int>(n);
            count = n;
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int findPar(int node) {
            if (node == parent[node]) return node;
            return parent[node] = findPar(parent[node]);
        }

        void unionNodes(int x, int y) {
            x = findPar(x), y = findPar(y);
            if (x != y) parent[x] = y, count--;
        }

        int getCount() {
            return count;
        }
    };

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        UnionFind uf(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                    uf.unionNodes(i, j);
            }
        }
        return n - uf.getCount();
    }
};