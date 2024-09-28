#include <iostream>
#include <stdexcept>
#include <limits>
#include "customVector.h"
#include "customQueue.h"

using namespace std;

template<typename T>
class DirectedGraph {
private:
    struct Edge {
        int node;
        T weight;
    };

    int numVertices;
    customVector<customVector<Edge>> adjList;

    void dfsUtil(int node, customVector<bool>& visited) {
        visited[node] = true;
        cout << node << " ";

        for (const Edge& edge : adjList[node]) {
            if (!visited[edge.node]) {
                dfsUtil(edge.node, visited);
            }
        }
    }

    void dfsTopoSort(int node, customVector<bool>& visited, customVector<int>& stack) {
        visited[node] = true;

        for (const Edge& edge : adjList[node]) {
            if (!visited[edge.node]) {
                dfsTopoSort(edge.node, visited, stack);
            }
        }

        // All neighbors visited, push to stack
        stack.push_back(node);
    }

    bool detectCycleUtil(int node, customVector<bool>& visited, customVector<bool>& recStack) {
        visited[node] = true;
        recStack[node] = true;

        for (const Edge& edge : adjList[node]) {
            if (!visited[edge.node]) {
                if (detectCycleUtil(edge.node, visited, recStack)) {
                    return true;
                }
            } else if (recStack[edge.node]) {
                return true;                                     // Cycle detected
            }
        }
        recStack[node] = false;                                  // Remove from recursion stack
        return false;
    }

public:
    // Constructors
    DirectedGraph(int vertices) {
        numVertices = vertices;
        adjList.resize(numVertices);
    }

    DirectedGraph(const customVector<customVector<int>>& edges) {
        numVertices = 0;

        // Determine number of vertices
        for (const auto& edge : edges) {
            if (edge[0] >= numVertices) numVertices = edge[0] + 1;                       // Adjust for 0-indexing
            if (edge[1] >= numVertices) numVertices = edge[1] + 1;                       // Adjust for 0-indexing
        }

        adjList.resize(numVertices);

        // Build the graph
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adjList[u].push_back({v, wt});
        }
    }

    void BFS(int startnode) {
        if (startnode < 0 || startnode >= numVertices) 
            throw invalid_argument("Invalid start node: " + to_string(startnode));

        customVector<bool> visited(numVertices, false);
        customQueue<int> q;

        visited[startnode] = true;
        q.push(startnode);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (const Edge& edge : adjList[node]) {
                if (!visited[edge.node]) {
                    visited[edge.node] = true;
                    q.push(edge.node);
                }
            }
        }
        cout << endl;
    }

    void DFS(int startnode) {
        if (startnode < 0 || startnode >= numVertices) 
            throw invalid_argument("Invalid start node: " + to_string(startnode));

        customVector<bool> visited(numVertices, false);
        dfsUtil(startnode, visited);
        cout << endl;
    }

    bool detectCycle() {
        customVector<bool> visited(numVertices, false);
        customVector<bool> recStack(numVertices, false);

        for (int i = 0; i < numVertices; ++i) {
            if (!visited[i]) {
                if (detectCycleUtil(i, visited, recStack)) {
                    return true;
                }
            }
        }
        return false;
    }

    int shortestPath(int startNode, int endNode) {
        if (startNode < 0 || startNode >= numVertices || endNode < 0 || endNode >= numVertices) {
            throw invalid_argument("Invalid start or end node: " + to_string(startNode) + ", " + to_string(endNode));
        }

        if (startNode == endNode) {
            return 0;
        }

        customVector<int> distance(numVertices, numeric_limits<int>::max());
        distance[startNode] = 0;

        customQueue<int> q;
        q.push(startNode);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (Edge& edge : adjList[node]) {
                if (distance[node] + edge.weight < distance[edge.node]) {
                    distance[edge.node] = distance[node] + edge.weight;
                    q.push(edge.node);
                }
            }
        }

        // If endNode is unreachable, return -1
        return (distance[endNode] == numeric_limits<int>::max()) ? -1 : distance[endNode];
    }

    bool pathExist(int startnode, int endnode) {
        if (startnode < 0 || startnode >= numVertices || endnode < 0 || endnode >= numVertices) {
            throw invalid_argument("Invalid start or end node: " + to_string(startnode) + ", " + to_string(endnode));
        }

        customVector<bool> visited(numVertices, false);
        customQueue<int> q;

        visited[startnode] = true;
        q.push(startnode);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == endnode) {
                return true;
            }

            for (Edge& edge : adjList[node]) {
                if (!visited[edge.node]) {
                    visited[edge.node] = true;
                    q.push(edge.node);
                }
            }
        }
        return false;
    }

    DirectedGraph<T> reverse() {
        DirectedGraph<T> reversedGraph(numVertices);

        for (int u = 0; u < numVertices; ++u) {
            for (Edge& edge : adjList[u]) {
                reversedGraph.adjList[edge.node].push_back({u, edge.weight});
            }
        }
        return reversedGraph;
    }

    customVector<int> toposort() {
        if (detectCycle()) {
            throw runtime_error("Graph is not a DAG. Topological sorting is not possible.");
        }

        customVector<bool> visited(numVertices, false);
        customVector<int> stack;

        // Perform DFS for topological sorting
        for (int i = 0; i < numVertices; ++i) {
            if (!visited[i]) {
                dfsTopoSort(i, visited, stack);
            }
        }

        // Reverse the stack to get the correct order
        customVector<int> result(stack.rbegin(), stack.rend());
        return result;
    }
};