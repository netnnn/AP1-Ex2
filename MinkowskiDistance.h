#ifndef MINKOWSKIDISTANCE_H
#define MINKOWSKIDISTANCE_H

#include <vector>
#include "Distance.h"
using namespace std;

class MinkowskiDistance : public Distance{
    private:
    double p;
    
    public:
    MinkowskiDistance(double p);
    double getDistance(vector<double> vec1, vector<double> vec2, int vectorSizes);
};

#endif
