#ifndef STUDENT_GRAPH
#define STUDENT_GRAPH

#include "binary_heap.h"
#include <vector>
#include <list>
#include <cstdio>

using namespace std;

//This file is for your graph implementation.
//Add everything you need in between the "ifndef and "endif" statements.
//Do not put anything outside those statements

/* Graph Class */
class Graph {

private:
    // Vector of list where each list is an adjacency list for a vertex
    vector<list<pair<int, double>>> vertices;

public:
    /* Constructor */
    Graph(int N) : vertices(N + 1) {}


    /* Getter for size */
    int getSize() {
        return vertices.size();
    }

    /* Add edge from u to v with weight w */
    void addEdge(int u, int v, double w) {
        vertices[u].push_back(make_pair(v, w));
    }

    /* Check if edge exists from u to v */
    double getAdjacentVertex(int u, int v) {
        for (auto adj : vertices[u]) {
            if (adj.first == v)
                return adj.second;
        }
        return -1;
    }

    /* Run dijkstra's algorithm */
    void dijkstra(int start) {

        int s = start;

        // Auxillary arrays
        int* prev = new int[getSize()];
        double* dist = new double[getSize()];
        bool* visited = new bool[getSize()];

        for (int i = 0; i <= getSize(); i++) {
            prev[i] = -1;
            dist[i] = 9999;
            visited[i] = false;
        }
        dist[s] = 0;
        visited[s] = false;

        // Make binary heap for dijkstra
        // Heap format <weight, <vertex, previous>>
        BinaryHeap<pair<double, pair<int, int>>> heap;

        // insert starting vertex
        heap.insert(make_pair(0, make_pair(s, -1)));

        // run while heap is not empty
        while (!heap.isEmpty()) {

            // get minimum vertex from heap
            pair<double, pair<int, int>> p = heap.findMin();
            heap.deleteMin();
            s = p.second.first;

            // if vertex is not visited
            if (!visited[s]) {
                // mark as visited
                visited[s] = true;

                // Update if current distance is lower
                if (dist[s] > p.first) {
                    dist[s] = p.first;
                    prev[s] = p.second.second;
                }
                // Add all vertices from adjacency list of current vertex
                for (auto adj : vertices[s]) {
                    if (!visited[adj.first]) {
                        heap.insert(make_pair(dist[s] + adj.second, make_pair(adj.first, s)));
                    }
                }
            }
        }

        // Output Code
        for (int i = 1; i < getSize(); i++) {
            cout << i << ": ";
            // If distance == MAX, there is no path
            if (dist[i] == 9999) {
                cout << "not_possible";
            }
            else {
                // Create array to store path
                vector<int> path;
                int p = i;
                // Use prev array to push path to array
                while (p != -1) {
                    path.push_back(p);
                    p = prev[p];
                }
                // Print path in reverse order
                for (int i = path.size() - 1; i >= 0; --i) {
                    cout << path[i] << " ";
                }

                // Print Cost
                cout << "cost: ";
                printf("%0.1f", dist[i]);
            }
            cout << endl;
        }

        // Free allocated memory
        delete[] visited;
        delete[] dist;
        delete[] prev;
    }

};


#endif
