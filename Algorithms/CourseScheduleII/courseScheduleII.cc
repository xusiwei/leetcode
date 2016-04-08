/*
copyright xu(xusiwei1236@163.com), all right reserved.

Course Schedule II
===================

There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]


Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.


For example:
2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]

4, [[1,0],[2,0],[3,1],[3,2]]
There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.


click to show more hints.

Hints:

This problem is equivalent to finding the topological order in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
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
    vector<int> findOrder(int N, vector<pair<int, int>>& E) {
        if (N == 0) return {};
        if (N == 1) return {0};

        vector<int> indegree(N, 0);
        for (int i = 0; i < E.size(); i++) {
            indegree[E[i].first]++;
        }

        queue<int> q; // store the zero indegree vertex
        for (int i = 0; i < N; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> result;
        vector<bool> cutted(E.size(), false);
        while (!q.empty()) {
            int t = q.front(); q.pop();
            result.push_back(t);
            for (int i = 0; i < E.size(); i++) {
                const int s = E[i].second, e = E[i].first;
                if (s == t && !cutted[i]) {
                    cutted[i] = true;
                    if (--indegree[e] == 0) {
                        q.push(e);
                    }
                }
            }
        }
        if (result.size() != N) return {};
        return result;
    }
};


class Solution2 {
public:
    vector<int> findOrder(int N, vector<pair<int, int>>& E) {
        if (N == 0) return {};
        if (N == 1) return {0};

        vector<int> indegree(N, 0);
        vector<vector<int>> adjacent(N);
        for (auto p : E) {
            indegree[p.first]++;
            adjacent[p.second].push_back(p.first);
        }

        queue<int> q; // store the zero indegree vertex
        for (int i = 0; i < N; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> result;
        vector<bool> marked(N, false);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            marked[v] = true;
            result.push_back(v);
            for (int e : adjacent[v]) {
                if (!marked[e] && --indegree[e] == 0) {
                    q.push(e);
                }
            }
        }
        if (result.size() != N) return {};
        return result;
    }
};

template <typename Vector>
void printVector(const Vector& v) {
    cout << "[";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ", ";
    }
    cout << "]" << endl;
}

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

    printVector(Solution().findOrder(n, edges));
    printVector(Solution2().findOrder(n, edges));
    return 0;
}
