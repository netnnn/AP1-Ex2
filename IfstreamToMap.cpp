#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "IfstreamToMap.h"
#include "StrToVector.h"

using namespace std;

map<vector<double>, string> IfstreamToMap::ifstreamToMap(string filePath, int vectorSize){
    ifstream file;
    file.open(filePath);

    map<vector<double>, string> map;

    string line;
    while(getline(file,line)){

        vector<string> vecStr = StrToVector::strToVector(line, ',');
        if (vecStr.size()-1 != vectorSize) continue;

        vector<double> vecDbl;
        int i;
        for(i = 0; i < vecStr.size()-1; i++){
            try {
                double d = stod(vecStr[i]);
                vecDbl.push_back(d);
            }
            catch(exception e) {
                break;
            }
        }
        if (i != vecStr.size()-1) continue;

        map.insert({vecDbl, vecStr[i]});
    }
    return map;
}