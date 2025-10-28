/*
 * CSC-301
 * project3.cpp
 * Fall 2025
 *
 * Partner 1:
 * Partner 2:
 * Date:
 */

#include "project3.hpp"

using namespace std;

/*
 * createAdjacencyMatrix
 */
vector<double> createAdjacencyMatrix(vector<double> &rates, 
                                     vector<string> &currencies) {
    vector<double> adjMatrix(rates);
    return adjMatrix;
}

/*
 * detectArbitrage
 */
vector<int> detectArbitrage(vector<double> &adjMatrix, 
                            vector<string> &currencies, 
                            double tol) {

    // Get the number of vertices and initialize the dist and prev values.
    int n = currencies.size();
    vector<double> distances( n, numeric_limits<double>::infinity() );
    vector<int> previous( n, -1 );
    
    // Create the cycle.
    vector<int> cycle;

    // Return the cycle.
    return cycle;
}