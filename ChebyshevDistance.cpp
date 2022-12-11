#include <vector>
#include <cmath>
#include "ChebyshevDistance.h"
using namespace std;

/**
 * calculates the chebyshev distance between two vectors.
 * @param vec1 the first vector
 * @param vec2 the second vector
 * @param vectorSizes the size of the two vectors
 * @return the distance.
 */
double getChebyshevDistance(vector<double> vec1, vector<double> vec2, int vectorSizes){
    //initializing the distance as the first distance between the vectors.
    double distance = abs(vec1[0] - vec2[0]);
    for (int i = 1; i < vectorSizes; i++) {
        if (distance < abs(vec1[i] - vec2[i]))
            distance = abs(vec1[i] - vec2[i]);
    }
    return distance;

}