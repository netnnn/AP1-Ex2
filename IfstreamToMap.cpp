#include <map>
#include <vector>
#include <string>
#include <iostream>
#include "IfstreamToMap.h"
#include "StrToVector.h"

using namespace std;

map<vector<double>, string> IfstreamToMap::ifstreamToMap(ifstream ifstream, int vectorSize){
    map<vector<double>, string> map;
    while(!ifstream.eof()){

        //Initializing a string and reading a line from the users input into it and constructing a stream from the string.
        string line;
        getline(ifstream, line);
        vector<string> vecStr = StrToVector::strToVector(line, ',');
        if (vecStr.size()-1 != vectorSize) continue;

        vector<double> vecDbl;
        int i = 0;
        for(i; i < vecStr.size()-1; i++){
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
