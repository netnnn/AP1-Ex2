#include "KNN.h"
#include <vector>
#include <iostream>
#include "list"
#include "Distance.h"
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



list<vector<double>> knnList(vector<double> vector1, Distance distance, list<vector<double>> vecList, int k) {
    if (k > vecList.size()){
        cout << "Error, K is bigger than the list";
    }
    vectorCmp vc(vector1, distance);
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