<h1 align="center">AP1</h1>

<p align="center">The project contains different methods to calculate the distance between 2 vectors of the same size. <br/>
The main method reads 2 lines from the users input, converts them to a vector and if they are the same size, calculates and prints al of the different distances. <br/>
So far, the distances taken into account are: Euclidean, Manhattan, Canberra, Chebyshev, and Minkowski. <br/>
The main uses methods LineToVector which reads a line and returns a vector from that line and the different distance calculating methods. <br/>
(Note: Minkowski uses a constant P for its calculation, we chose to calculate the distance with constant P=2 like the example in the exercise) <br/>
It prints the numbers with precision of 1 digit after the dot if the number is whole, and with precision of 16 digits after the dot if else. <br/>
The code is modular: each function is in its own cpp file. This help keep the code organised and efficient. Also, Since the Manhattan and Euclidean distances are just private instaces of Minkowski with p = 1 and p = 2 accordingly, they are implemented by calling the minkowski method with the according P. </p>

## Links

- [Repo](https://github.com/Eviassor789/AP1 "AP1 Repo")

## How to run

In the project directory: <br/>
To compile: g++ -std=c++11 *.cpp <br/>
To execute: ./a.out <br/>
To use: enter 2 lines of numbers seperated by a single space (each line represents a vector). For example: <br/>
1 2 3 <br/>
3 2 1 <br/>

## Authors

**Netanel Teller**

- [Profile](https://github.com/netnnn)
- [Email](netanel7227@gmail.com)

**Evyatar Assor**

- [Profile](https://github.com/Eviassor789)
- [Email](eviassor@gmail.com)

