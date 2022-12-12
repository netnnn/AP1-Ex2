#include "CanberraDistance.h"
#include "ChebyshevDistance.h"
#include "MinkowskiDistance.h"
#include "EuclidianDistance.h"
#include "ManhattanDistance.h"
#include "LineToVector.h"
#include "Distance.h"
#include <vector>
#include <iostream>

using namespace std;

int main() {

    Distance* x;
    ManhattanDistance man = ManhattanDistance();
    EuclidianDistance euc = EuclidianDistance();
    CanberraDistance can = CanberraDistance();
    ChebyshevDistance che = ChebyshevDistance();
    MinkowskiDistance min = MinkowskiDistance();

    vector<double> a = LineToVector::lineToVector();
    vector<double> b = LineToVector::lineToVector();

    int c;
    cin >> c;
    cin.clear();

    if(c == 1)
        x = &man;
    if(c == 2)
        x = &euc;
    if(c == 3)
        x = &can;
    if(c == 4)
        x = &che;
    if(c == 5)
        x = &min;

    double d = x->getDistance(a,b,a.size());
    cout << d << endl;

}