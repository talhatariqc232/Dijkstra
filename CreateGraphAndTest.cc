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

void AdjacencyQueries(Graph *g, string filename){

    // Open the file
    ifstream fin(filename.c_str());

    // Read pair of vertices
    int u, v;
    fin >> u >> v;
    while(fin){
        // Get distance from first to second vertices
        double res = g->getAdjacentVertex(u, v);
        cout << u << " " << v << ": ";
        // If distance is -1, they are not connected
        if(res == -1){
            cout << "not_connected" << endl;
        }
        // Else print distance
        else{
            cout << "connected " << res << endl;
        }
        // Read pair of vertices
        fin >> u >> v;
    }

}

int testGraphDriver(int argc, char** argv) {

    // Load graph from file
    Graph *g = GetGraphFromFile(argv[1]);
    
    // Open the queries file and run the queries
    AdjacencyQueries(g, argv[2]);

    // free the space taken by the graph
    delete g;
    return 0;
}

// Do not modify anything below this line

int main(int argc, char** argv) {
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " <GRAPH_File>" << "<ADJACENCY_QUERYFILE>" << endl;
        return 0;
    }

    testGraphDriver(argc, argv);

    return 0;
}
