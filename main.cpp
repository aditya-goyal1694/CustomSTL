#include "customSTL.h"
#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
  // // VECTOR

  // cout<<"VECTOR"<<endl<<endl;

  // customVector<int> vec;
  // cout << "Initial capacity: " << vec.capacity() << ", size: " << vec.size()
  // << "\n";

  // // Push back some elements
  // for (int i = 0; i < 25; ++i) {
  //     vec.push_back(i);
  //     cout << "Pushed back: " << i << ", size: " << vec.size() << ",
  //     capacity: " << vec.capacity() << "\n";
  // }

  // // Access elements using operator[]
  // cout << "Element at index 10: " << vec[10] << "\n";
  // cout << "Front element: " << vec.front() << "\n";
  // cout << "Back element: " << vec.back() << "\n";

  // // Resize the vector
  // vec.resize(30);
  // cout << "Resized to 30, new size: " << vec.size() << ", capacity: " <<
  // vec.capacity() << "\n";

  // // Assign new values
  // vec.assign(5, 100);
  // cout << "Assigned 5 elements with value 100, new size: " << vec.size() <<
  // "\n";

  // // Insert an element at position 2
  // int valToInsert = 50;
  // vec.insert(2, valToInsert);
  // cout << "Inserted " << valToInsert << " at position 2, new size: " <<
  // vec.size() << "\n";

  // // Sort the vector
  // vec.sort();
  // cout << "Sorted the vector: ";
  // for (const auto& elem : vec) {
  //     cout << elem << " ";
  // }
  // cout << "\n";

  // // Find an element
  // int index = vec.find(10);
  // cout << "Element 10 found at index: " << index << "\n";

  // // Reverse the vector
  // vec.reverse();
  // cout << "Reversed the vector: ";
  // for (const auto& elem : vec) {
  //     cout << elem << " ";
  // }
  // cout << "\n";

  // // Rotate left by 3
  // vec.rotateLeft(3);
  // cout << "Rotated left by 3: ";
  // for (const auto& elem : vec) {
  //     cout << elem << " ";
  // }
  // cout << "\n";

  // // Rotate right by 2
  // vec.rotateRight(2);
  // cout << "Rotated right by 2: ";
  // for (const auto& elem : vec) {
  //     cout << elem << " ";
  // }
  // cout << "\n";

  // // Clear the vector
  // vec.clear();
  // cout << "Cleared the vector, new size: " << vec.size() << "\n";

  // //
  // -------------------------------------------------------------------------------------------------------------------------------------------
  // LINKED LIST

  // cout<<endl<<endl<<"LINKED LIST"<<endl<<endl;

  // LinkedList<int> list;

  // // Insert elements
  // cout << "Inserting elements: 10, 20, 30, 40, 50" << endl;
  // list.insert(10);
  // list.insert(20);
  // list.insert(30);
  // list.insert(40);
  // list.insert(50);
  // list.printList();

  // // Insert at specific position
  // cout << "Inserting 25 at position 2" << endl;
  // list.insert(25, 2);
  // list.printList();

  // // Delete an element
  // cout << "Deleting element 30" << endl;
  // list.deleteNode(30);
  // list.printList();

  // // Delete from the end
  // cout << "Deleting last element" << endl;
  // list.deleteNode();
  // list.printList();

  // // Find an element
  // try {
  //     cout << "Finding element 20 at position: " << list.find(20) << endl;
  // } catch (const runtime_error& e) {
  //     cout << e.what() << endl;
  // }

  // // Sort the list
  // cout << "Sorting the list" << endl;
  // list.sort();
  // list.printList();

  // // Reverse the list
  // cout << "Reversing the list" << endl;
  // list.reverse();
  // list.printList();

  // // Rotate the list
  // cout << "Rotating the list left by 2" << endl;
  // list.rotateLeft(2);
  // list.printList();

  // cout << "Rotating the list right by 1" << endl;
  // list.rotateRight(1);
  // list.printList();

  // //
  // -------------------------------------------------------------------------------------------------------------------------------------------
  // // CIRCULAR LINKED LIST

  // cout<<endl<<endl<<"CIRCULAR LINKED LIST"<<endl<<endl;

  // CircularLinkedList<int> cll;

  // // Insert elements
  // cout << "Inserting elements: 10, 20, 30, 40" << endl;
  // cll.insert(10);
  // cll.insert(20);
  // cll.insert(30);
  // cll.insert(40);
  // cll.printList();

  // // Insert at specific position
  // cout << "Inserting 25 at position 2" << endl;
  // cll.insert(25, 2);
  // cll.printList();

  // // Find element
  // try {
  //     cout << "Finding element 25: Position " << cll.find(25) << endl;
  // } catch (const runtime_error& e) {
  //     cout << e.what() << endl;
  // }

  // // Delete element
  // cout << "Deleting element 20" << endl;
  // cll.deleteNode(20);
  // cll.printList();

  // // Delete from the end
  // cout << "Deleting last element" << endl;
  // cll.deleteNode();
  // cll.printList();

  // // Reverse the list
  // cout << "Reversing the list" << endl;
  // cll.reverse();
  // cll.printList();

  // // Rotate left
  // cout << "Rotating left by 1" << endl;
  // cll.rotateLeft(1);
  // cll.printList();

  // // Rotate right
  // cout << "Rotating right by 2" << endl;
  // cll.rotateRight(2);
  // cll.printList();

  // // Attempting to find a non-existent element
  // try {
  //     cout << "Finding element 100" << endl;
  //     cout << "Position: " << cll.find(100) << endl;
  // } catch (const runtime_error& e) {
  //     cout << e.what() << endl;
  // }

  // // Delete a non-existent element
  // try {
  //     cout << "Deleting element 100" << endl;
  //     cll.deleteNode(100);
  // } catch (const runtime_error& e) {
  //     cout << e.what() << endl;
  // }

  // //
  // -------------------------------------------------------------------------------------------------------------------------------------------
  // // DOUBLY LINKED LIST

  // cout<<endl<<endl<<"DOUBLY LINKED LIST"<<endl<<endl;

  // doublyLinkedList<int> dll;

  // // Insert elements
  // dll.insert(1);
  // dll.insert(2);
  // dll.insert(3);
  // dll.insert(4);
  // dll.printList();

  // // Insert at position
  // dll.insert(5, 2);
  // dll.printList();

  // // Delete a node
  // dll.deleteNode(2);
  // dll.printList();

  // // Sort the dll
  // dll.sort();
  // dll.printList();

  // // Reverse the dll
  // dll.reverse();
  // dll.printList();

  // // Rotate left
  // dll.rotateLeft(1);
  // dll.printList();

  // // Rotate right
  // dll.rotateRight(1);
  // dll.printList();

  // //
  // -------------------------------------------------------------------------------------------------------------------------------------------
  // // STACK

  // cout<<endl<<endl<<"STACK"<<endl<<endl;

  // customStack<int> stack;

  // // Pushing elements onto the stack
  // cout << "Pushing elements: 5, 3, 8, 1" << endl;
  // stack.push(5);
  // stack.push(3);
  // stack.push(8);
  // stack.push(1);

  // // Displaying the top element
  // cout << "Top element: " << stack.top() << endl;

  // // Displaying the maximum and minimum elements
  // cout << "Maximum element: " << stack.maxele() << endl;
  // cout << "Minimum element: " << stack.minele() << endl;

  // // Popping an element
  // cout << "Popping top element..." << endl;
  // stack.pop();
  // cout << "New top element: " << stack.top() << endl;

  // // Displaying maximum and minimum after popping
  // cout << "Maximum element: " << stack.maxele() << endl;
  // cout << "Minimum element: " << stack.minele() << endl;

  // // Clearing the stack
  // cout << "Clearing the stack..." << endl;
  // stack.clear();

  // // Checking if the stack is empty
  // if (stack.isEmpty()) {
  //     cout << "The stack is now empty." << endl;
  // }

  // // Trying to get the maximum and minimum from an empty stack (this will
  // throw an exception) try {
  //     cout << "Maximum element: " << stack.maxele() << endl;
  // } catch (const std::underflow_error& e) {
  //     cout << "Error: " << e.what() << endl;
  // }

  // //
  // -------------------------------------------------------------------------------------------------------------------------------------------
  // // MONOTONIC STACK

  // cout<<endl<<endl<<"MONOTONIC STACK"<<endl<<endl;

  // monotonicStack<int> ascendingStack(false);

  // // Creating a descending monotonic stack
  // monotonicStack<int> descendingStack(true);

  // // Pushing elements onto the ascending stack
  // cout << "Pushing elements 10, 15, 5 onto the ascending stack" << endl;
  // int a = 10, b = 15, c = 5;
  // ascendingStack.push(a);
  // ascendingStack.push(b);
  // ascendingStack.push(c);

  // // Pushing elements onto the descending stack
  // cout << "Pushing elements 20, 18, 25 onto the descending stack" << endl;
  // int x = 20, y = 18, z = 25;
  // descendingStack.push(x);
  // descendingStack.push(y);
  // descendingStack.push(z);

  // // Displaying the top elements of both stacks
  // cout << "Top of ascending stack: " << ascendingStack.top() << endl;
  // cout << "Top of descending stack: " << descendingStack.top() << endl;

  // // Popping elements from both stacks
  // cout << "Popping top element from both stacks" << endl;
  // ascendingStack.pop();
  // descendingStack.pop();

  // // Displaying the new top elements
  // cout << "New top of ascending stack: " << ascendingStack.top() << endl;
  // cout << "New top of descending stack: " << descendingStack.top() << endl;

  // // Clearing both stacks
  // cout << "Clearing both stacks..." << endl;
  // ascendingStack.clear();
  // descendingStack.clear();

  // // Checking if the stacks are empty
  // if (ascendingStack.isEmpty()) {
  //     cout << "Ascending stack is empty." << endl;
  // }
  // if (descendingStack.isEmpty()) {
  //     cout << "Descending stack is empty." << endl;
  // }

  // //
  // -------------------------------------------------------------------------------------------------------------------------------------------
  // // QUEUE

  // cout<<endl<<endl<<"QUEUE"<<endl<<endl;

  // customQueue<int> queue;

  // // Push elements into the queue
  // cout << "Pushing elements 10, 5, 20, 7 into the queue" << endl;
  // queue.push(10);
  // queue.push(5);
  // queue.push(20);
  // queue.push(7);

  // // Display the front element
  // cout << "Front element: " << queue.front() << endl;

  // // Get and display the maximum and minimum elements in the queue
  // cout << "Maximum element in the queue: " << queue.maxele() << endl;
  // cout << "Minimum element in the queue: " << queue.minele() << endl;

  // // Pop the front element and display the new front
  // cout << "Popping front element..." << endl;
  // queue.pop();
  // cout << "New front element: " << queue.front() << endl;

  // // Get and display the new maximum and minimum elements in the queue
  // cout << "Maximum element after pop: " << queue.maxele() << endl;
  // cout << "Minimum element after pop: " << queue.minele() << endl;

  // // Pop another element
  // cout << "Popping another element..." << endl;
  // queue.pop();
  // cout << "New front element: " << queue.front() << endl;

  // // Clear the queue
  // cout << "Clearing the queue..." << endl;
  // queue.clear();

  // // Check if the queue is empty
  // if (queue.isEmpty()) {
  //     cout << "Queue is empty." << endl;
  // } else {
  //     cout << "Queue is not empty." << endl;
  // }

  // //
  // -------------------------------------------------------------------------------------------------------------------------------------------
  // // DEQUE

  // cout<<endl<<endl<<"DEQUE"<<endl<<endl;

  // customDeque<int> deque;

  // // Push elements into the back of the deque
  // cout << "Pushing elements 10, 20, 30 to the back of the deque" << endl;
  // deque.push_back(10);
  // deque.push_back(20);
  // deque.push_back(30);

  // // Push elements into the front of the deque
  // cout << "Pushing elements 5, 1 to the front of the deque" << endl;
  // deque.push_front(5);
  // deque.push_front(1);

  // // Display the front and back elements
  // cout << "Front element: " << deque.front() << endl;
  // cout << "Back element: " << deque.back() << endl;

  // // Get and display the maximum and minimum elements in the deque
  // cout << "Maximum element in the deque: " << deque.maxele() << endl;
  // cout << "Minimum element in the deque: " << deque.minele() << endl;

  // // Pop the front element and display the new front
  // cout << "Popping front element..." << endl;
  // deque.pop_front();
  // cout << "New front element: " << deque.front() << endl;

  // // Pop the back element and display the new back
  // cout << "Popping back element..." << endl;
  // deque.pop_back();
  // cout << "New back element: " << deque.back() << endl;

  // // Get and display the new maximum and minimum elements in the deque
  // cout << "Maximum element after pops: " << deque.maxele() << endl;
  // cout << "Minimum element after pops: " << deque.minele() << endl;

  // // Clear the deque
  // cout << "Clearing the deque..." << endl;
  // deque.clear();

  // // Check if the deque is empty
  // if (deque.isEmpty()) {
  //     cout << "Deque is empty." << endl;
  // } else {
  //     cout << "Deque is not empty." << endl;
  // }

  // //
  // -------------------------------------------------------------------------------------------------------------------------------------------
  // // MINHEAP

  // cout<<endl<<endl<<"MINHEAP"<<endl<<endl;

  // MinHeap<int> minheap;

  // // Insert elements into the MinHeap
  // cout << "Inserting elements: 15, 10, 20, 5, 7 into the MinHeap" << endl;
  // minheap.insert(15);
  // minheap.insert(10);
  // minheap.insert(20);
  // minheap.insert(5);
  // minheap.insert(7);

  // // Get the minimum element
  // cout << "Current minimum element: " << minheap.getMin() << endl;

  // // Extract the minimum element and display it
  // cout << "Extracting minimum element: " << minheap.extractMin() << endl;

  // // Display the new minimum element
  // cout << "New minimum element: " << minheap.getMin() << endl;

  // // Insert more elements
  // cout << "Inserting elements: 3, 12" << endl;
  // minheap.insert(3);
  // minheap.insert(12);

  // // Display the current minimum element again
  // cout << "Current minimum element: " << minheap.getMin() << endl;

  // // Extract more elements and display them
  // cout << "Extracting minimum element: " << minheap.extractMin() << endl;
  // cout << "Extracting another minimum element: " << minheap.extractMin() <<
  // endl;

  // // Check if the minheap is empty
  // if (minheap.isEmpty()) {
  //     cout << "Heap is empty now." << endl;
  // } else {
  //     cout << "Heap is not empty." << endl;
  // }

  // // Get the size of the minheap
  // cout << "Current size of the minheap: " << minheap.gets() << endl;

  // //
  // -------------------------------------------------------------------------------------------------------------------------------------------
  // // MAXHEAP

  // cout<<endl<<endl<<"MAXHEAP"<<endl<<endl;

  // MaxHeap<int> maxheap;

  // // Insert elements into the MaxHeap
  // cout << "Inserting elements: 10, 20, 30, 5, 40 into the MaxHeap" << endl;
  // maxheap.insert(10);
  // maxheap.insert(20);
  // maxheap.insert(30);
  // maxheap.insert(5);
  // maxheap.insert(40);

  // // Get the maximum element
  // cout << "Current maximum element: " << maxheap.getMax() << endl;

  // // Extract the maximum element and display it
  // cout << "Extracting maximum element: " << maxheap.extractMax() << endl;

  // // Display the new maximum element
  // cout << "New maximum element: " << maxheap.getMax() << endl;

  // // Insert more elements
  // cout << "Inserting elements: 25, 50" << endl;
  // maxheap.insert(25);
  // maxheap.insert(50);

  // // Display the current maximum element again
  // cout << "Current maximum element: " << maxheap.getMax() << endl;

  // // Extract more elements and display them
  // cout << "Extracting maximum element: " << maxheap.extractMax() << endl;
  // cout << "Extracting another maximum element: " << maxheap.extractMax() <<
  // endl;

  // // Check if the maxheap is empty
  // if (maxheap.isEmpty()) {
  //     cout << "Heap is empty now." << endl;
  // } else {
  //     cout << "Heap is not empty." << endl;
  // }

  // // Get the size of the maxheap
  // cout << "Current size of the maxheap: " << maxheap.getSize() << endl;

  // //
  // -------------------------------------------------------------------------------------------------------------------------------------------
  // // BINARY TREE

  // cout<<endl<<endl<<"BINARY TREE"<<endl<<endl;

  // BinaryTree<int> tree;

  // // Inserting elements into the tree
  // tree.insert(10);
  // tree.insert(20);
  // tree.insert(30);
  // tree.insert(40);
  // tree.insert(50);
  // tree.insert(60);

  // // Displaying the tree traversals
  // cout << "Preorder traversal: ";
  // tree.preorder();

  // cout << "Inorder traversal: ";
  // tree.inorder();

  // cout << "Postorder traversal: ";
  // tree.postorder();

  // cout << "Level order traversal (BFS): ";
  // tree.levelOrder();

  // cout << "DFS traversal: ";
  // tree.dfs();

  // // Modify a node's value
  // cout << "Modifying 30 to 35..." << endl;
  // tree.modify(30, 35);

  // // Display the modified inorder traversal
  // cout << "Inorder traversal after modification: ";
  // tree.inorder();

  // // Finding and deleting an element
  // if (tree.find(50)) {
  //     cout << "50 found, deleting 50..." << endl;
  //     tree.deleteElement(50);
  // }

  // // Level order traversal after deletion
  // cout << "Level order traversal after deletion: ";
  // tree.levelOrder();

  // // Getting the parent of a node
  // try {
  //     cout << "Parent of 60: " << tree.getParent(60) << endl;
  // } catch (const std::runtime_error& e) {
  //     cout << e.what() << endl;
  // }

  // // Getting the size of the tree
  // cout << "Size of the tree: " << tree.getSize() << endl;

  // //
  // -------------------------------------------------------------------------------------------------------------------------------------------
  // // BINARY SEARCH TREE (BST)

  // cout<<endl<<endl<<"BINARY SEARCH TREE"<<endl<<endl;

  // BinarySearchTree<int> bst;

  // // Inserting elements into the BST
  // bst.insert(50);
  // bst.insert(30);
  // bst.insert(70);
  // bst.insert(20);
  // bst.insert(40);
  // bst.insert(60);
  // bst.insert(80);

  // // Traversal outputs
  // cout << "Inorder Traversal: ";
  // bst.inorder();

  // cout << "Preorder Traversal: ";
  // bst.preorder();

  // cout << "Postorder Traversal: ";
  // bst.postorder();

  // cout << "Level Order Traversal (BFS): ";
  // bst.levelOrder();

  // cout << "DFS Traversal: ";
  // bst.dfs();

  // // Searching for an element
  // int searchElement = 60;
  // if (bst.search(searchElement)) {
  //     cout << "Element " << searchElement << " found in the tree." << endl;
  // } else {
  //     cout << "Element " << searchElement << " not found in the tree." <<
  //     endl;
  // }

  // // Removing an element
  // int removeElement = 70;
  // cout << "Removing element " << removeElement << " from the tree." << endl;
  // bst.remove(removeElement);

  // // Traversal after deletion
  // cout << "Inorder Traversal after deletion: ";
  // bst.inorder();

  // // Trying to remove a non-existent element
  // try {
  //     bst.remove(100);
  // } catch (runtime_error& e) {
  //     cout << "Error: " << e.what() << endl;
  // }

  // // Tree height
  // cout << "Height of the tree: " << bst.getHeight() << endl;

  // //
  // -------------------------------------------------------------------------------------------------------------------------------------------
  // // UNDIRECTED GRAPH

  // cout<<endl<<endl<<"UNDIRECTED GRAPH"<<endl<<endl;

  // customVector<customVector<int>> edges = {
  //     {0, 1}, {0, 2}, {1, 2}, {1, 3}, {3, 4}
  // };

  // // Create an undirected graph using the edges
  // UndirectedGraph<int> graph(edges);

  // // Display BFS traversal starting from node 0
  // cout << "BFS traversal starting from node 0: ";
  // graph.bfs(0);

  // // Display DFS traversal starting from node 0
  // cout << "DFS traversal starting from node 0: ";
  // graph.dfs(0);

  // // Check if there is a cycle in the graph
  // bool hasCycle = graph.detectCycle();
  // cout << "Does the graph have a cycle? " << (hasCycle ? "Yes" : "No") <<
  // endl;

  // // Find shortest path between two nodes
  // int startNode = 0;
  // int endNode = 4;
  // int shortestDistance = graph.shortestPath(startNode, endNode);
  // if (shortestDistance != -1) {
  //     cout << "Shortest path from node " << startNode << " to node " <<
  //     endNode << " is: " << shortestDistance << endl;
  // } else {
  //     cout << "No path exists between node " << startNode << " and node " <<
  //     endNode << endl;
  // }

  // // Check if there is a path between two nodes
  // bool pathExists = graph.pathExist(startNode, endNode);
  // cout << "Does a path exist from node " << startNode << " to node " <<
  // endNode << "? " << (pathExists ? "Yes" : "No") << endl;

  // -------------------------------------------------------------------------------------------------------------------------------------------
  // DIRECTED GRAPH

  cout << endl << endl << "DIRECTED GRAPH" << endl << endl;

  customVector<customVector<int>> directedEdges = {
      {0, 1, 4}, {0, 2, 1}, {1, 3, 1}, {2, 3, 5}, {3, 0, 3}};

  // Create a directed graph
  DirectedGraph<int> directedGraph(directedEdges);

  cout << "Breadth-First Search (BFS) from node 0:\n";
  directedGraph.bfs(0);

  cout << "\nDepth-First Search (DFS) from node 0:\n";
  directedGraph.dfs(0);

  cout << "\nShortest Path from node 0 to 4:\n";
  int shortestDistance1 = directedGraph.shortestPath(0, 4);
  if (shortestDistance1 != -1) {
    cout << "Shortest path distance: " << shortestDistance1 << endl;
  } else {
    cout << "No path exists between 0 and 4\n";
  }

  cout << "\nCycle Detection:\n";
  if (directedGraph.detectCycle()) {
    cout << "Cycle detected in the graph.\n";
  } else {
    cout << "No cycle in the graph.\n";
  }

  cout << "\nPath existence between node 0 and 4:\n";
  if (directedGraph.pathExist(0, 4)) {
    cout << "Path exists between 0 and 4.\n";
  } else {
    cout << "No path between 0 and 4.\n";
  }

  // Reverse the graph
  DirectedGraph<int> reversedGraph1 = directedGraph.reverse();
  cout << "\nBreadth-First Search (BFS) of reversed graph from node 0:\n";
  reversedGraph1.bfs(0);

  return 0;
}