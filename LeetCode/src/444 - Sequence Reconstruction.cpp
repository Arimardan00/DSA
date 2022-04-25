/*
Problem Name: Sequence Reconstruction
Problem Link: https://leetcode.com/problems/sequence-reconstruction/ || https://www.lintcode.com/problem/605/description
Tag: graph, topological sort
Concept: use topological sort + only 1 node in queue at a time
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    /**
     * @param org: a permutation of the integers from 1 to n
     * @param seqs: a list of sequences
     * @return: true if it can be reconstructed only one or false
     */
    bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs) {
        int n = org.size();
        vector<vector<int>> graph(n + 1);
        int count = 0;
        for (auto seq : seqs) {
            count += seq.size();
            if (seq.size() >= 1 && (seq[0] <= 0 || seq[0] > n)) return false;
            for (int i = 1; i < seq.size(); i++) {
                if (seq[i] <= 0 || seq[i] > n) return false;
                if (find(graph[seq[i - 1]].begin(), graph[seq[i - 1]].end(), seq[i]) == graph[seq[i - 1]].end())
                    graph[seq[i - 1]].push_back(seq[i]);
            }
        }

        // case: [1], [] or [1], [[], []]
        if (count < n) return false;

        vector<int> indegree(n + 1);
        for (int v = 1; v <= n; v++) {
            for (int it : graph[v]) {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int v = 1; v <= n; v++)
            if (indegree[v] == 0) q.push(v);

        vector<int> toposort;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            toposort.push_back(node);
            if (!q.empty()) return false;
            for (int it : graph[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }

        if (toposort == org) return true;
        return false;
    }
};
