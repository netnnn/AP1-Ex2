#include <iostream>
#include <vector>
#include <cmath>
#include "LineToVector.h"
#include "EuclidianDistance.h"
#include "ManhattanDistance.h"
#include "ChebyshevDistance.h"
#include "CanberraDistance.h"
#include "MinkowskiDistance.h"
using namespace std;
/**
 * prints the distance by its precision, if distance
 * is int, then print one number only after the '.'
 * else print all the 16.
 * @param distance
 */
void printByPrecision(double distance) {
    cout.precision(16);
    if (distance == floor(distance)) cout.precision(1);
    cout << fixed << distance << endl;
}

/**
 * @brief the main function which gets 2 lines and converts them into vectors and then prints the different
 * distances between them.
 * 
 * @return int 0 if the program ran successfully.
 */
int main() {

    //Getting 2 vectors from the users input.
    vector<double> vec1 = lineToVector();
    vector<double> vec2 = lineToVector();

    //If they arent the same size, cant calculate distance, so exit.
    if (vec1.size() != vec2.size()) {
        cout << "Vectors are different sizes, cant calculate distance" << endl;
        exit(0);
    }

    //They have the same size.
    int vectorSizes = vec1.size();

    //Getting all the distances
    double euclideanDistance = getEuclidianDistance(vec1, vec2, vectorSizes);
    double manhattanDistance = getManhattanDistance(vec1, vec2, vectorSizes);
    double chebyshevDistance = getChebyshevDistance(vec1, vec2, vectorSizes);
    double canberraDistance = getCanberraDistance(vec1, vec2, vectorSizes);
    double minkowskiDistance = getMinkowskiDistance(vec1, vec2, vectorSizes, 2);

    //Printing all the distances accordingly. if the number is an int, with precision 1. else with precision 16.
    printByPrecision(euclideanDistance);
    printByPrecision(manhattanDistance);
    printByPrecision(chebyshevDistance);
    printByPrecision(canberraDistance);
    printByPrecision(minkowskiDistance);

    return 0;

}

//compile with g++ *.cpp
//then run ./a.out