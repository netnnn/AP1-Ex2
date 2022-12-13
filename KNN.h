//
// Created by evias on 11/12/2022.
//

#ifndef AP1_EX2_KNN_H
#define AP1_EX2_KNN_H


#include <string>
#include "Distance.h"
#include "map"

class KNN {
public:
    static map<double, vector<double>> knnMap(vector<double> vector1, Distance distance, map<vector<double>, string> vecMap, int k);
    static string findVectorType(map<double, vector<double>> KDistanceMap, map<vector<double>, string> vecMap);

};


#endif //AP1_EX2_KNN_H
