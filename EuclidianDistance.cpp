#include <vector>
#include <cmath>
#include <iostream>
#include "EuclidianDistance.h"
#include "MinkowskiDistance.h"
using namespace std;

/**
 * @brief Get the Euclidian Distance between two vectors of the same size
 * 
 * @param vec1 vector 1
 * @param vec2 vector 2
 * @param vectorSizes the size of the two vectors
 * @return double the euclidean distance between the two vectors
 */
double getEuclidianDistance(vector<double> vec1, vector<double> vec2, int vectorSizes){
    //calculating by the Euclidean distance formula by the minkowski formula.
    return getMinkowskiDistance(vec1, vec2, vectorSizes, 2);

}