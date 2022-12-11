#include <vector>
#include <iostream>
#include <sstream>
#include "LineToVector.h"
using namespace std;

/**
 * @brief a method that reads a line of the users input. The line should be doubles seperated by spaces. It then splits the
 * doubles from each other and pushes them into a vector and returns the vector. If the input isnt as expected, whether
 * it be non-number characters or too many spaces, it throws an error and exits the program.
 * @return vector<double> a vector of doubles
 */
vector<double> lineToVector(){
    //Initializing a vector of doubles.
    vector<double> vec;

    //Initializing a string and reading a line from the users input into it and constructing a stream from the string.
    string line;
    getline(cin, line);
    stringstream lineStream(line);

    /* Splitting the line according to the space character and storing each part in a string called word, then trying
    to convert it to a double. If it succeeds, push it into the vector. If not, its an error so exit. */
    string word;
    while(getline(lineStream, word, ' ')){
        try {
            double num = stod(word);
        }
        catch (exception e){
            cout << "Invalid vector structure" << endl;
            exit(0);
        }
        vec.push_back(stod(word));
    }

    //Returning the vector built from the line.
    return vec;
}

