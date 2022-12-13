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

using namespace std;

int main() {

    string a;
    cin >> a;
    vector<string> v = StrToVector::strToVector(a, '\n');
    for (auto x : v) {
        cout << x << " ";
    }

    ifstream file;
    file.open("iris_classified.csv");
    string line;
    while(getline(file, line)) {
        vector<string> b = StrToVector::strToVector(line, ',');
        for (auto x : b) {
            cout << x << " ";
        }
        cout << "\n";
    }
}