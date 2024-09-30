# UndirectedGraph Class Documentation

## Overview
The UndirectedGraph class template represents an undirected graph using an adjacency list. It supports operations such as breadth-first search (BFS), depth-first search (DFS), cycle detection, and shortest path calculations.

## Key Features:
- Dynamic management of an undirected graph with generic edge weights.
- Provides methods for graph traversal, cycle detection, and path existence checking.
- Utilizes a custom vector for adjacency lists, allowing for flexible storage of graph edges.

---

## Constructors

### Graph Constructor
```cpp
UndirectedGraph(customVector<customVector<int>> &edges);
```
- Initializes the graph from a list of edges, where each edge is represented by a vector of integers (with optional weight).
- Automatically computes the number of vertices based on the edges provided.

---

## Graph Operations

### `bfs` Method
```cpp
void bfs(int startnode);
```
- Performs a breadth-first search starting from the specified node.
- Outputs the visited nodes in the order they are traversed.
- Throws invalid_argument if the start node is out of bounds.

### `dfs` Method
```cpp
void dfs(int startnode);
```
- Performs a depth-first search starting from the specified node.
- Outputs the visited nodes in the order they are traversed.
- Throws invalid_argument if the start node is out of bounds.

### `detectCycle` Method
```cpp
bool detectCycle();
```
- Checks if the graph contains a cycle.
- Returns true if a cycle is detected; otherwise, returns false.

### `shortestPath` Method
```cpp
int shortestPath(int startNode, int endNode);
```
- Calculates the shortest path from startNode to endNode.
- Returns the number of edges in the shortest path or -1 if the endNode is unreachable.
- Throws invalid_argument if either node is out of bounds.

### `pathExist` Method
```cpp
bool pathExist(int startnode, int endnode);
```
- Checks if there is a path from startnode to endnode.
- Returns true if a path exists; otherwise, returns false.
- Throws invalid_argument if either node is out of bounds.

---

## Private Methods

- `dfsUtil(int node, customVector<bool> &visited)`: Helper function for performing DFS recursively.
- `detectCycleUtil(int node, customVector<bool> &visited, int parent)`: Helper function to detect cycles in the graph recursively.

---

## Edge Structure

### Edge
The graph implementations use a nested Edge structure to represent connections between nodes.

```cpp
struct Edge
{
    int node;   // The index of the connected node.
    T weight;   // The weight of the edge connecting the nodes.

    Edge(int n, T w) : node(n), weight(w) {}
};
```

- `node`: The index of the connected node.
- `weight`: The weight of the edge connecting the nodes.

---

## Member Variables

`int numVertices`: The total number of vertices in the graph.
`customVector<customVector<Edge>> adjList`: An adjacency list that stores edges for each vertex.