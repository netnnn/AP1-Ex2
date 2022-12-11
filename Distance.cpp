#include "Distance.h"
#include <vector>
#include <cmath>
using namespace std;

double getDistance(vector<double> vec1, vector<double> vec2, int vectorSizes){
    //initializing the distance as 0
    double distance = 0;
    //calculating by the manhattan distance formula.
    for (int i = 0; i < vectorSizes; i++) {
        if(vec1[i] != 0 || vec2[i] != 0)
            distance += abs(vec1[i] - vec2[i])/(abs(vec1[i]) + abs(vec2[i]));
    }
    //returning the distance
    return distance;
}