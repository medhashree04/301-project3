/*
 * CSC-301
 * project3.cpp
 * Fall 2025
 *
 * Partner 1: Natalie Nardone
 * Partner 2: Medhashree Adhikari
 * Date: October 31, 2025
 */

#include "project3.hpp"

using namespace std;

/*
 * createAdjacencyMatrix
 * Input:
 *      vector<double> &rates: Reference to the vector of rates
 *      vector<string> &currencies: Reference to the string of currencies
 * Output:
 *      vector<double: the corresponding adjacency matrix
 * Function:
 *      The function takes in a matrix of the exchange rates and a vector of 
 *      currency labels. It will return the corresponding adjacency matrix.
 */
vector<double> createAdjacencyMatrix(vector<double> &rates, 
                                     vector<string> &currencies) {
    vector<double> adjMatrix(rates);

    for (int i : adjMatrix) {
        if (adjMatrix[i] != 0) {
            adjMatrix[i] = log10(1/adjMatrix[i]);
        } // cond check
    } // for loop

    return adjMatrix;
}

/*
 * detectArbitrage
  * Input:
 *      vector<double> &adjMatrix: Reference to the adjacency matrix 
 *      vector<string> &currencies: Reference to the currencies
 *      double tol: The tolerance value (does NOT change)
 * Output:
 *      vector<int>: Vector of vertex labels that stand for negative cost cycle
 * Function:
 */
vector<int> detectArbitrage(vector<double> &adjMatrix, 
                            vector<string> &currencies, 
                            double tol) {

    // Get the number of vertices and initialize the dist and prev values.
    int n = currencies.size();
    vector<double> distances( n, numeric_limits<double>::infinity() );
    vector<int> previous( n, -1 );

    int start = 0; // index 0
    distances[start] = 0; // setting init distance to 0

    int vertex_updated = -1; // index in matrix

    // loops over the |V| - 1 - iterations
    for(int i = 0; i < n; i++) {
        for(int u = 0; u < n; u++) { // row
            for(int v = 0; v < n; v++) { // column
                int edge = u * n + v;
                if (distances[v] > distances[u] + adjMatrix[edge] + tol) {
                    distances[v] = distances[u] + adjMatrix[edge];
                    previous[v] = u;
                    if(i == n-1){
                        vertex_updated = v;
                    }
                } // cond check
            } // inner inner loop - loop through rows
        } // inner loop - loop through cols/vertex
    } // for loop

    // Create the cycle.
    vector<int> cycle;
    if(vertex_updated == -1) {
        return cycle;
    } // no cycle

    // finding cycle
    int current = vertex_updated;
    while (true) {
        cycle.push_back(current);
        if (count(cycle.begin(), cycle.end(), current) == 2) {
            break;
        } else {
            current = previous[current];
        }
    }

    // erase
    int j;
    for (j = 0; j < cycle.size(); j++) {
        if (cycle[j] == current) {
            break;
        }
    }
    cycle.erase(cycle.begin() + j - 1); // erase after finding j
    
    // reverse cycle
    reverse(cycle.begin(), cycle.end());

    // Return the cycle.
    return cycle;
}