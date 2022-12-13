//
// Created by evias on 11/12/2022.
//

#ifndef AP1_EX2_KNN_H
#define AP1_EX2_KNN_H

#include <list>

class KNN {
public:
    static list<vector<double>> knnList(vector<double> vector1, Distance* distance, map<vector<double>, string> vecMap, int k);
    static string findVectorType(list<vector<double>> KDistanceList, map<vector<double>, string> vecMap);
};


#endif //AP1_EX2_KNN_H
