/*
copyright xu(xusiwei1236@163.com), all right reserved.

Course Schedule
================

There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]


Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?


For example:
2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.


click to show more hints.

Hints:

This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
Topological sort could also be done via BFS.
*/
#include <stdlib.h>
#include <queue>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canFinish(int N, vector<pair<int, int>>& E) {
        if (N == 0) return false;
        if (N == 1) return true;
        vector<int> indeg(N, 0);
        for (int i = 0; i < E.size(); i++) {
            indeg[E[i].first]++;
        }

        queue<int> q; // store the zero indegree vertex
        for (int i = 0; i < N; i++) {
            if (indeg[i] == 0) {
                q.push(i);
                // cout << ">" << i << endl;
            }
        }

        int count = 0;
        vector<bool> used(E.size(), false);
        while (!q.empty()) {
            int t = q.front(); q.pop();
            // cout << "t>" << t << endl;
            for (int i = 0; i < E.size(); i++) {
                const int s = E[i].second, e = E[i].first;
                if (s == t && !used[i]) {
                    used[i] = true;
                    count++;
                    if (--indeg[e] == 0) {
                        q.push(e);
                    }
                }
            }
        }
        return count == E.size();
    }
};


class Solution2 {
public:
    bool canFinish(int N, vector<pair<int, int>>& E) {
        if (N == 0) return false;
        if (N == 1) return true;

        vector<int> indeg(N, 0);
        vector<vector<int>> adjlist(N);
        for (auto p : E) {
            indeg[p.first]++;
            adjlist[p.second].push_back(p.first);
        }

        queue<int> q; // store the zero indegree vertex
        for (int i = 0; i < N; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;
        vector<bool> vis(N, false);
        while (!q.empty()) {
            int start = q.front(); q.pop();
            vis[start] = true;
            count++;
            for (auto e : adjlist[start]) {
                if (!vis[e] && indeg[e]) {
                    if (--indeg[e] == 0) {
                        q.push(e);
                    }
                }
            }
        }
        return count == N;
    }
};

int main(int argc, char* argv[])
{
    int n = 2;
    vector<pair<int, int>> edges{{0, 1}};
    if (argc > 1) {
        n = atoi(argv[1]);
        srand(time(NULL));
        int noe = (rand()>>2) % (n*n/2); // number of edges.
        for (int i = 0; i < noe; i++) {
            pair<int, int> p((rand()>>3) % n, (rand()>>6) % n);
            if (p.first == p.second) continue;
            bool collided = false;
            for (auto e : edges) {
                if (e.first == p.first && e.second == p.second) {
                    collided = true;
                    break;
                }
            }
            if (!collided) {
                cout << p.first << "\t" << p.second << endl;
                edges.push_back(p);
            }
        }
    }

    cout << Solution().canFinish(n, edges) << endl;
    cout << Solution2().canFinish(n, edges) << endl;
    return 0;
}
