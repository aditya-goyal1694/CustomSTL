#include <iostream>
#include <stdexcept>
#include <limits>
#include "customVector.h"
#include "customQueue.h"
using namespace std;

#ifndef GRAPH_H
#define GRAPH_H

template <typename T>
class UndirectedGraph
{
private:
    struct Edge
    {
        int node;
        T weight;
    };

    int numVertices;
    customVector<customVector<Edge>> adjList;

    void dfsUtil(int node, customVector<bool> &visited)
    {
        visited[node] = true;
        cout << node << " ";

        for (const Edge &edge : adjList[node])
        {
            if (!visited[edge.node])
            {
                dfsUtil(edge.node, visited);
            }
        }
    }

    bool detectCycleUtil(int node, customVector<bool> &visited, int parent)
    {
        visited[node] = true;

        for (const Edge &edge : adjList[node])
        {
            if (!visited[edge.node])
            {
                if (detectCycleUtil(edge.node, visited, node))
                {
                    return true;
                }
            }
            else if (edge.node != parent)
            {
                return true;
            }
        }
        return false;
    }

public:
    // Constructor
    UndirectedGraph(customVector<customVector<int>> &edges)
    {
        numVertices = 0;

        for (auto &edge : edges)
        {
            if (edge[0] > numVertices)
                numVertices = edge[0];
            if (edge[1] > numVertices)
                numVertices = edge[1];
        }
        numVertices++; // Adjust for 0-indexing

        adjList.resize(numVertices);

        // Build the graph
        for (const auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            T wt = (edge.size() > 2) ? edge[2] : T(); // Default weight is 0

            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }
    }

    void bfs(int startnode)
    {
        if (startnode < 0 || startnode >= numVertices)
            throw invalid_argument("Invalid start node.");

        customVector<bool> visited(numVertices, false);
        customQueue<int> q;

        visited[startnode] = true;
        q.push(startnode);

        while (!q.isEmpty())
        {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (const Edge &edge : adjList[node])
            {
                if (!visited[edge.node])
                {
                    visited[edge.node] = true;
                    q.push(edge.node);
                }
            }
        }
        cout << endl;
    }

    void dfs(int startnode)
    {
        if (startnode < 0 || startnode >= numVertices)
            throw invalid_argument("Invalid start node.");

        customVector<bool> visited(numVertices, false);
        dfsUtil(startnode, visited);
        cout << endl;
    }

    bool detectCycle()
    {
        customVector<bool> visited(numVertices, false);
        for (int i = 0; i < numVertices; ++i)
        {
            if (!visited[i])
            {
                if (detectCycleUtil(i, visited, -1))
                {
                    return true;
                }
            }
        }
        return false;
    }

    int shortestPath(int startNode, int endNode)
    {
        if (startNode < 0 || startNode >= numVertices || endNode < 0 || endNode >= numVertices)
        {
            throw invalid_argument("Invalid start or end node.");
        }

        if (startNode == endNode)
        {
            return 0;
        }

        customVector<int> distance(numVertices, numeric_limits<int>::max());

        for (int i = 0; i < numVertices; ++i)
        {
            distance[i] = numeric_limits<int>::max();
        }
        distance[startNode] = 0;

        customQueue<int> q;
        q.push(startNode);

        while (!q.isEmpty())
        {
            int node = q.front();
            q.pop();

            for (const Edge &edge : adjList[node])
            {
                if (distance[node] + 1 < distance[edge.node])
                {
                    distance[edge.node] = distance[node] + 1;
                    q.push(edge.node);

                    if (edge.node == endNode)
                    {
                        return distance[endNode];
                    }
                }
            }
        }

        // If endNode is unreachable, return -1
        int result = (distance[endNode] == numeric_limits<int>::max()) ? -1 : distance[endNode];
        return result;
    }

    bool pathExist(int startnode, int endnode)
    {
        if (startnode < 0 || startnode >= numVertices || endnode < 0 || endnode >= numVertices)
        {
            throw invalid_argument("Invalid start or end node.");
        }

        customVector<bool> visited(numVertices, false);
        customQueue<int> q;

        visited[startnode] = true;
        q.push(startnode);

        while (!q.isEmpty())
        {
            int node = q.front();
            q.pop();

            if (node == endnode)
            {
                return true;
            }

            for (const Edge &edge : adjList[node])
            {
                if (!visited[edge.node])
                {
                    visited[edge.node] = true;
                    q.push(edge.node);
                }
            }
        }
        return false;
    }
};

#endif