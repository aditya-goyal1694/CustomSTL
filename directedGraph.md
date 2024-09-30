# DirectedGraph Class Documentation

## Overview
The DirectedGraph class template represents a directed graph using an adjacency list. It supports various graph operations including traversal, cycle detection, and shortest path calculations.

## Key Features:
- Dynamic management of a directed graph with generic edge weights.
- Provides methods for graph traversal (BFS and DFS), cycle detection, and path existence checking.
- Allows the construction of the graph from a list of edges or by specifying the number of vertices.

---

## Constructors

### Default Constructor
```cpp
DirectedGraph(int vertices);
```
- Initializes a directed graph with a specified number of vertices.

### Edge-Based Constructor
```cpp
DirectedGraph(const customVector<customVector<int>> &edges);
```
- Initializes the graph from a list of edges, where each edge is represented by a vector of integers (with weights).
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
- Checks if the directed graph contains a cycle.
- Returns true if a cycle is detected; otherwise, returns false.

### `shortestPath` Method
```cpp
int shortestPath(int startNode, int endNode);
```
- Calculates the shortest path from startNode to endNode.
- Returns the weight of the shortest path or -1 if the endNode is unreachable.
- Throws invalid_argument if either node is out of bounds.

### `pathExist` Method
```cpp
bool pathExist(int startnode, int endnode);
```
- Checks if there is a path from startnode to endnode.
- Returns true if a path exists; otherwise, returns false.
- Throws invalid_argument if either node is out of bounds.

### `reverse` Method
```cpp
DirectedGraph<T> reverse();
```
- Returns a new directed graph that is the reverse of the current graph, where all edges are reversed.

---

## Private Methods

- `dfsUtil(int node, customVector<bool> &visited)`: Helper function for performing DFS recursively.
- `detectCycleUtil(int node, customVector<bool> &visited, customVector<bool> &recStack)`: Helper function to detect cycles in the graph recursively using a recursion stack.

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

- `struct Edge`: A structure representing a directed edge in the graph, containing a node index and a weight.
- `int numVertices`: The total number of vertices in the directed graph.
- `customVector<customVector<Edge>> adjList`: An adjacency list that stores edges for each vertex.