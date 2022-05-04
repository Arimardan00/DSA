/*
Problem Name: Number of Islands
Problem Link: https://leetcode.com/problems/number-of-islands/
Tag: Graph, BFS, DFS, Union-Find(Disjoint Set)
Concept:
    - Use disjoint set and count of 1 to find the ans
*/
#include <bits/stdc++.h>
using namespace std;

// Using Disjoint Set
class Solution {
   public:
    int findPar(int node, vector<int> &parent) {
        if (node == parent[node]) return node;
        return parent[node] = findPar(parent[node], parent);
    }

    void unionNode(int x, int y, int &count, vector<int> &parent) {
        x = findPar(x, parent);
        y = findPar(y, parent);
        if (x == y) return;
        parent[y] = x;
        count--;
    }

    int numIslands(vector<vector<char>> &grid) {
        int n = grid.size(), m = grid[0].size();

        int count = 0;
        vector<int> parent(n * m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                parent[i * m + j] = i * m + j;
                if (grid[i][j] == '1') count++;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '0') continue;

                int index = i * m + j;
                if (j < m - 1 && grid[i][j + 1] == '1') unionNode(index, index + 1, count, parent);
                if (i < n - 1 && grid[i + 1][j] == '1') unionNode(index, index + m, count, parent);
            }
        }

        return count;
    }
};
