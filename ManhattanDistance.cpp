#include <vector>
#include <cmath>
#include "ManhattanDistance.h"
#include "MinkowskiDistance.h"
using namespace std;

/**
 * @brief Get the Manhattan Distance between two vectors.
 * 
 * @param vec1 vector 1
 * @param vec2 vector 2
 * @param vectorSizes the size of the two vectors
 * @return double the manhattan distance between the two vectors
 */
double getManhattanDistance(vector<double> vec1, vector<double> vec2, int vectorSizes){
    //calculating by the Manhatten distance formula by the minkowski formula.
    return getMinkowskiDistance(vec1, vec2, vectorSizes, 1);
}