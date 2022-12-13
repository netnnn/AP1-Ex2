#include "KNN.h"
#include <vector>
#include <iostream>
#include "Distance.h"
#include <list>
#include <map>
#include <string>
using namespace std;

class vectorCmp {
public:
    vector<double> vec;
    Distance* distance;
    vectorCmp(vector<double> vector1, Distance* distance1){
        distance = distance1;
        vec = vector1;
    }
    bool operator()(const vector<double>& vec1,const vector<double>& vec2) {
        if (distance->getDistance(vec, vec1, vec.size())
            < distance->getDistance(vec, vec2, vec.size())) {
            return true;
        }
        return false;
    }
};

list<vector<double>> KNN::knnList(vector<double> vector1, Distance* distance, map<vector<double>, string> vecMap, int k) {
    vectorCmp vc(vector1, distance);
    list<vector<double>> vecList;
    for (auto v : vecMap) {
        vecList.push_back(v.first);
    }
    vecList.sort(vc);
    list<vector<double>> KList;
    list<vector<double>>::iterator it;
    int i = 0;
    for (i = 0; i < k; i++) {
        it = vecList.begin();
        KList.splice(KList.end(), vecList, it);
    }
    return KList;
}

string KNN::findVectorType(list<vector<double>> KDistanceList, map<vector<double>, string> vecMap){
    map<string, int> vecType;
    map<string, int>::iterator typeIter;

    for (vector<double> v : KDistanceList) {
        vecType[vecMap[v]] = 0;
    }

    for (vector<double> v : KDistanceList) {
        vecType[vecMap[v]] += 1;
    }

    string maxType = vecType.begin()->first;
    for (typeIter = vecType.begin(); typeIter != vecType.end() ; typeIter++) {
        if (vecType[maxType] < typeIter->second){
            maxType = typeIter->first;
        }
    }
    return maxType;
}