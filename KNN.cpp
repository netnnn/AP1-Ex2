#include "KNN.h"
#include <vector>
#include <iostream>
#include "Distance.h"
#include "map"
using namespace std;

class vectorCmp {
public:
    vector<double> vec;
    Distance distance;
    vectorCmp(vector<double> vector1, Distance distance1){
        distance = distance1;
        vec = vector1;
    }
    bool operator()(const vector<double>& vec1,const vector<double>& vec2) {
        if (distance.getDistance(vec, vec1, vec.size())
            < distance.getDistance(vec, vec2, vec.size())) {
            return false;
        }
        return true;
    }
};



map<double, vector<double>> knnMap(vector<double> vector1, Distance distance, map<vector<double>, string> vecMap, int k) {
    map<double, vector<double>> distanceMap;
    map<double, vector<double>> KDistanceMap;
    int vecSize = vector1.size();
    double dis;
    map<vector<double>, string>::iterator it;
    for (it = vecMap.begin(); it != vecMap.end() ; it++ ) {
        dis = distance.getDistance(vector1, it->first, vecSize);
        distanceMap[dis] = it->first;
    }
    map<double, vector<double>>::iterator iter;
    int i = 0;
    for (iter = distanceMap.begin(); i < k; iter++) {
        KDistanceMap[iter->first] = iter->second;
        ++i;
    }
    return KDistanceMap;


//    vectorCmp vc(vector1, distance);
//    vecList.sort(vc);
//    list<vector<double>> KList;
//    list<vector<double>>::iterator it;
//    int i = 0;
//    for (i = 0; i < k; i++) {
//        it = vecList.begin();
//        KList.splice(KList.end(), vecList, it);
//    }
//    return KList;


}

string findVectorType(map<double, vector<double>> KDistanceMap, map<vector<double>, string> vecMap){
    map<string, int> vecType;
    map<string, int>::iterator typeIter;
    map<double, vector<double>>::iterator it;
//    for (typeIter = vecType.begin(); typeIter != vecType.end() ; typeIter++) {
//        typeIter->first =
//        typeIter->second = 0;
//    }
    for (it = KDistanceMap.begin(); it != KDistanceMap.end(); it++) {
        vecType[vecMap[it->second]] = 0;
    }

    for (it = KDistanceMap.begin(); it != KDistanceMap.end(); it++) {
        vecType[vecMap[it->second]] += 1;
    }

    string maxType = vecType.begin()->first;
    for (typeIter = vecType.begin(); typeIter != vecType.end() ; typeIter++) {
        if (vecType[maxType] < typeIter->second){
            maxType = typeIter->first;
        }
    }
    return maxType;
}