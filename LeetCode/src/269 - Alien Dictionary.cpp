/*
Problem Name: Alien Dictionary
Problem Link: https://leetcode.com/problems/alien-dictionary/ || https://www.lintcode.com/problem/892/
Tag: graph, topological sort
Concept: use priority queue in topological sort for human lexical sort
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    /**
     * @param words: a list of words
     * @return: a string which is correct order
     */
    string alienOrder(vector<string> &words) {
        unordered_map<char, vector<char>> graph;

        // create nodes for each of the char
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                char c = words[i][j];
                if (graph.count(c) == 0) {
                    graph[c] = vector<char>();
                }
            }
        }

        // create edge
        for (int i = 1; i < words.size(); i++) {
            string a = words[i - 1];
            string b = words[i];
            int j = 0;
            while (j < a.size() && j < b.size()) {
                if (a[j] != b[j]) {
                    graph[a[j]].push_back(b[j]);
                    break;
                }
                j++;
            }
            if (j == b.size() && j < a.size()) return "";
        }

        return toposort(graph, graph.size());
    }

    string toposort(unordered_map<char, vector<char>> &graph, int n) {
        priority_queue<char, vector<char>, greater<char>> q;
        unordered_map<char, int> indegree;
        for (auto p : graph) {
            indegree[p.first] = 0;
        }
        for (auto p : graph) {
            for (char it : p.second) {
                indegree[it]++;
            }
        }

        for (auto p : indegree) {
            if (p.second == 0) q.push(p.first);
        }

        string topo;
        while (!q.empty()) {
            char node = q.top();
            q.pop();
            topo += node;

            for (char it : graph[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }

        if (topo.size() == graph.size()) return topo;
        return "";
    }
};
