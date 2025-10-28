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