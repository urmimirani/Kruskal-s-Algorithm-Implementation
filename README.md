# Kruskal-s-Algorithm-Implementation

Authors: Urmi Riteshkumar Mirani, Tvisha Patel

## Overview
This project involves designing an abstract data type (ADT) for an undirected graph and implementing Kruskal’s algorithm to find the minimum spanning tree (MST). The graph data is read from a file, and the MST is computed using efficient algorithms.

## Setup Instructions

### Prerequisites
- C++ compiler (e.g., g++)
- Standard libraries (iostream, fstream, vector, algorithm)
### File Format
The input file (e.g., input.txt) should contain:
n m
x1 y1 w1
x2 y2 w2
...
xm ym wm
where n is the number of nodes, m is the number of edges, and each subsequent line represents an edge with nodes xi and yi and weight wi.

### Compiling and Running

1. Compile the code:
- g++ -o graph graph.cpp
- g++ -o kruskal kruskal.cpp

2. Run the graph operations:
- ./graph

3. Run Kruskal’s algorithm:
- ./kruskal


## Project Structure

- graph.cpp: Contains the implementation of the Graph ADT.
- kruskal.cpp: Contains the implementation of Kruskal’s MST algorithm.

## Features

### Graph ADT Implementation:
- Methods to add/remove edges and vertices.
- Methods to check edge existence and get the degree of a vertex.
- Print adjacency matrix for visual representation.

### Kruskal’s MST Algorithm:
- Read graph data from a file.
- Sort edges and apply union-find to construct MST.
- Output the total weight of the MST.

## Conclusion

In conclusion, this project successfully demonstrates the implementation of an ADT for an undirected graph and Kruskal's algorithm for finding the MST. The solution ensures efficient data handling and correctness through union-find optimizations. Kruskal’s algorithm is a reliable and widely used method for solving MST problems in various domains.
