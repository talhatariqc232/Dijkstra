// CSCI 335 Homework #6

// Your name:
 

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "graph.h"

using namespace std;


Graph *GetGraphFromFile(string filename){
    
    // Open file
    ifstream fin(filename.c_str());
    int n;
    // Input number of vertices
    fin >> n;
    fin.ignore(10, '\n');

    // Create new graph with n vertices
    Graph *g = new Graph(n);

    int v;
    double w;
    string buffer;
    // Read n number of lines
    for (int i = 1; i <= n; i++) {
        // Take a line as input
        getline(fin, buffer);
        // use that line as input for the adjacency list
        stringstream ss(buffer);
        ss >> v;
        // Input pair of vertices
        ss >> v >> w;
        while (ss) {
            // Add an edge to the graph
            g->addEdge(i, v, w);
            ss >> v >> w;
        }
    }
    return g;
}

int findPathDriver(int argc, char **argv) {
    
    // Convert argument to integer
    int s = stoi(argv[2]);

    // Input graph from file
    Graph *g = GetGraphFromFile(argv[1]);
    
    // Run dijkstra starting from vertex specified by argument
    g->dijkstra(s);
    
    delete g;

    return 0;
}

// Do not modify anything below this line

int main(int argc, char **argv) {
    if (argc != 3) {
		cout << "Usage: " << argv[0] << " <GRAPH_FILE>" << "<STARTING_VERTEX>" << endl;
		return 0;
    }

    findPathDriver(argc, argv);

    return 0;
}
