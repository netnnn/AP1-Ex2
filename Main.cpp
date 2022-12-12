#include "CanberraDistance.h"
#include "ChebyshevDistance.h"
#include "MinkowskiDistance.h"
#include "EuclidianDistance.h"
#include "ManhattanDistance.h"
#include "LineToVector.h"
#include "Distance.h"
#include "KNN.h"
#include <vector>
#include <iostream>
#include "string.h"

using namespace std;

int main(int argv, char** args) {
    const char *dis;
    int k = 0;
    try {
        k = stoi(args[1]);
        string file = args[2];
        dis = args[3];
    } catch (exception exception) {
        cout << "invalid arguments" << endl;
        exit(0);
    }
    Distance* x;
    ManhattanDistance man = ManhattanDistance();
    EuclidianDistance euc = EuclidianDistance();
    CanberraDistance can = CanberraDistance();
    ChebyshevDistance che = ChebyshevDistance();
    MinkowskiDistance min = MinkowskiDistance();

    if(strcmp("MAN", dis) == 0)
        x = &man;
    if(strcmp("AUC", dis) == 0)
        x = &euc;
    if(strcmp("CAN", dis) == 0)
        x = &can;
    if(strcmp("CHB", dis) == 0)
        x = &che;
    if(strcmp("MIN", dis) == 0)
        x = &min;

//    string c;
//    cin >> c;
//    cin.clear();

    while (true) {
        vector<double> vec;
        try {
            vec = LineToVector::lineToVector();
        } catch (exception e) {
            cout << "ERROR - illegal vector arguments" << endl;
            continue;
        }

        map<vector<double>, string> vecMap; //scan into vecMap

        map<double, vector<double>> KDistanceMap;
        KDistanceMap = KNN::knnMap(vec, *x, vecMap, k);

        string maxType; //the flower type that was the most common in the map
        maxType = KNN::findVectorType(KDistanceMap, vecMap);

        cout << maxType << endl;

    }
//    vector<double> b = LineToVector::lineToVector();
//    double d = x->getDistance(a,b,a.size());
//    cout << d << endl;

}