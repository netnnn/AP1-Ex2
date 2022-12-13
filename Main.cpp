#include "CanberraDistance.h"
#include "ChebyshevDistance.h"
#include "MinkowskiDistance.h"
#include "EuclidianDistance.h"
#include "ManhattanDistance.h"
#include "StrToVector.h"
#include "Distance.h"
#include <vector>
#include <iostream>
#include <fstream>
#include "IfstreamToMap.h"
#include <map>

using namespace std;

int main() {

    string a;
    getline(cin, a);
    vector<string> v = StrToVector::strToVector(a, ' ');

    for (auto x : v) {
        cout << x << " ";
    }

    string filePath= "/home/netanel/Desktop/Uni/AP1/AP1-Ex2/datasets/iris/iris_classified.csv";
    map<vector<double>, string> map = IfstreamToMap::ifstreamToMap(filePath, v.size());

    for(auto i = map.begin(); i != map.end(); i++) {
        for (auto x : i->first) {
            cout << x << " ";
        }
        cout << i->second;
        cout << "\n";
    }
}