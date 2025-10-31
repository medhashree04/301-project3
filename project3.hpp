/*
 * CSC-301
 * project3.cpp
 * Fall 2025
 *
 * Partner 1: Natalie Nardone
 * Partner 2: Medhashree Adhikari
 * Date: October 31, 2025
 * Acknowledgements: Eric Autry
 */


#ifndef PROJECT3_HPP_
#define PROJECT3_HPP_

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

/*
 * createAdjacencyMatrix
 */
std::vector<double> createAdjacencyMatrix(std::vector<double> &rates,
                                          std::vector<std::string> &currencies);

/*
 * detectArbitrage
 */
std::vector<int> detectArbitrage(std::vector<double> &adjMatrix,
                                 std::vector<std::string> &currencies,
                                 double tol=1e-15);

#endif  // PROJECT3_HPP_