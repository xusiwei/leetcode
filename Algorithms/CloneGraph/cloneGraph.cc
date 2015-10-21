/*
copyright xu(xusiwei1236@163.com), all right reserved.

Clone Graph
============

Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

OJ's undirected graph serialization:

Nodes are labeled uniquely.
We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.

As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

    First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
    Second node is labeled as 1. Connect node 1 to node 2.
    Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.

Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/

*/
#include <cassert>
#include <queue>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL) return NULL;
        
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> copy;
        queue<UndirectedGraphNode*> q;
        
        // copy nodes.
        q.push(node);        
        while( !q.empty() ) {
            auto p = q.front();
            q.pop();
            
            if(copy.find(p) == copy.end()) { // not visit.
                copy[p] = new UndirectedGraphNode(p->label);
                for(auto n: p->neighbors) {
                    q.push(n);
                }
            }
        }
        
        // copy edges.
        for(auto it : copy) {
            for(auto nb : it.first->neighbors) {
                it.second->neighbors.push_back(copy[nb]);
            }
        }
        return copy[node];
    }
};

void printGraph(UndirectedGraphNode* node) {
    unordered_set<UndirectedGraphNode*> m;
    queue<UndirectedGraphNode*> q;
    
    q.push(node);
    while( !q.empty() ) {
        auto p = q.front();
        q.pop();
        
        if(m.find(p) == m.end()) {
            cout << p->label;
            m.insert(p);
            for(auto nb : p->neighbors) {
                if(m.find(nb) == m.end()) {
                    cout << "," << nb->label;
                    q.push(nb);
                }
            }
            cout << "#";
        }
    }
    cout << endl;
}

UndirectedGraphNode* buildGraph(int edges[][2], int size) {
    auto nodes = new UndirectedGraphNode*[size];
    
    for(int i = 0; i < size; i++) {
        nodes[i] = new UndirectedGraphNode(i);
    }
    
    for(int i = 0; i < size; i++) {
        int n0 = edges[i][0];
        int n1 = edges[i][1];
        assert(0 <= n0 && n0 < size);
        assert(0 <= n1 && n1 < size);
        nodes[n0]->neighbors.push_back(nodes[n1]);
        nodes[n1]->neighbors.push_back(nodes[n0]);
    }
    
    auto ret = nodes[0];
    delete [] nodes;
    
    return ret;
}

#define ARRAYSIZE(a) sizeof(a)/sizeof(a[0])
int main(int argc, char* argv[])
{
#define TEST(...) do {                    \
    int e[][2] = {__VA_ARGS__};           \
    auto g = buildGraph(e, ARRAYSIZE(e)); \
    printGraph(g);                        \
    printGraph(Solution().cloneGraph(g)); \
    }while(0)

    TEST(0, 1, 0, 2, 1, 2, 2, 2);
    return 0;
}
