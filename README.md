<h1 align="center">AP1-EX2</h1>

<p align="center">The project contains a method that determines what is the flower type of vector. <br/>
The main method gets a number K which determines how many vectors to take for deciding what is the type of vector. <br/>
Also it gets a path to scan the vectors from, and a distance method that we will use in our calculations. <br/>
Then the main method reads line from the users input, converts it to a vector and returns its type, for infinity . <br/>
So far, the distances taken into account are: Euclidean(AUC), Manhattan(MAN), Canberra(CAN), Chebyshev(CHB), and Minkowski(MIN).<br/>
The main uses methods StrToVector which reads a line and returns a vector from that line. <br/>
And the method IfStreamToMap which scans the .csv file into a map of vectors and their types. <br/>
Also The main uses the functions knnList which calculates who are the closest K vectors to a given vector, <br/>
And the function findVectorType which returns the type that was the most common in the K closest vectors. <br/>
An ERROR! message will occur in the following cases: <br/> 
1. if the number of arguments is wrong. <br/>
2. if the distance type does not exist. <br/>
3. if the file does not exist. <br/>
4. if the vector is illegal (has a field that is not an integer). <br/>
5. if the vector has different length than the vectors that are in the file. <br/>
(Note: Minkowski uses a constant P for its calculation, we chose to calculate the distance with constant P=3 like the example in the exercise). <br/>
The code is modular: each function is in its own cpp file. This help keep the code organised and efficient. </p>

## Links

- [Repo](https://github.com/netnnn/AP1-Ex2 "AP1-Ex2 Repo")

## How to run

In the project directory: <br/>
To compile: make <br/>
To execute: ./a.out k file distance  <br/>
To use: enter one line of numbers seperated by a single space (each line represents a vector). For example: <br/>
1 2 3 4 <br/>

## Authors

**Netanel Teller**

- [Profile](https://github.com/netnnn)
- [Email](netanel7227@gmail.com)

**Evyatar Assor**

- [Profile](https://github.com/Eviassor789)
- [Email](eviassor@gmail.com)

