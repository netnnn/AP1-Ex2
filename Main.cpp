#include "CanberraDistance.h"
#include "ChebyshevDistance.h"
#include "MinkowskiDistance.h"
#include "EuclidianDistance.h"
#include "ManhattanDistance.h"
#include "StrToVector.h"
#include "IfstreamToMap.h"
#include "Distance.h"
#include "KNN.h"
#include <vector>
#include <iostream>
#include "string.h"
#include <map>
#include <list>

using namespace std;

int main(int argv, char* args[]) {
    const char *dis;
    string filePath;
    int k = 0;
    if(argv != 4) {
        cout << "ERROR! Illegal arguments" << endl;
        exit(0);
    }
    try {
        k = stoi(args[1]);
        filePath = args[2];
        dis = args[3];
    } catch (exception exception) {
        cout << "invalid arguments" << endl;
        exit(0);
    }

    Distance* x;
    ManhattanDistance man = ManhattanDistance();
    EuclidianDistance auc = EuclidianDistance();
    CanberraDistance can = CanberraDistance();
    ChebyshevDistance che = ChebyshevDistance();
    MinkowskiDistance min = MinkowskiDistance();

    if(strcmp("MAN", dis) == 0)
        x = &man;
    else if(strcmp("AUC", dis) == 0)
        x = &auc;
    else if(strcmp("CAN", dis) == 0)
        x = &can;
    else if(strcmp("CHB", dis) == 0)
        x = &che;
    else if(strcmp("MIN", dis) == 0)
        x = &min;
    else {
        cout << "ERROR! Invalid distance type" << endl;
        exit(0);
    }

    while (true) {
        vector<string> vecStr;
        vector<double> vec;
        string line;
        int i = 0;
        getline(cin, line);
        vecStr = StrToVector::strToVector(line, ' ');
        try {
            for (i = 0; i < vecStr.size(); i++) {
                double d = stod(vecStr[i]);
                vec.push_back(d);
            }
        } catch (exception e) {
            cout << "ERROR! illegal vector" << endl;
            continue;
        }

        map<vector<double>, string> vecMap;
        vecMap = IfstreamToMap::ifstreamToMap(filePath, vec.size()); //scan into vecMap
        if (vecMap.size() == 0){
            cout << "ERROR! no valid vectors to calculate distance with" << endl;
            continue;
        }
        if (vecMap.size() < k){
            k = vecMap.size();
        }

        list<vector<double>> KDistanceList;
        KDistanceList = KNN::knnList(vec, x, vecMap, k);

        // for (vector<double> v : KDistanceList) {
        //     for (auto x : v) {
        //         cout << x << " ";
        //     }
        //     cout << endl;
        // }

        string maxType; //the flower type that was the most common in the map
        maxType = KNN::findVectorType(KDistanceList, vecMap);

        cout << maxType << endl;

    }

}