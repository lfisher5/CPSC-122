/*
Class: CPSC 122-02
Team Member 1: Lauren Fisher
Team Member 2: None
Submitted By: Lauren Fisher
GU Username: lfisher5
File Name: project1.cpp
Program illustrates console i/o and for loops;
To Build: g++ project1.cpp 
To Execute: ./a.out filename
*/

#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

bool isPrime(int num);

int main(int argc, char* argv[]) {

int i, j, x, y;
int d = 2;
int q = 1;
int num = 0;
ofstream fout;


if(argc != 2) {
	cout << "Incorrect number of command line arguments!" << endl;
	exit(-1);
}
	
fout.open(argv[1]);


 cout << "How many prime numbers do you want to see?" << endl; 
 cin >> x;

 cout << "Distributed over how many columns" << endl; 
 cin >> y;
 


for(i = 2; i < x; i++) 
{
	while(isPrime(d) == false) 
	{  
		d++;//advances counter while function returns false
	}
	if(q == y) //if prime number is at edge of column
	{
		fout << d << endl;//writes prime number to output file and a newline
		q = 0;
	}
	else
	{
		fout << d << " ";//writes to output file with no newline
  	}
	d++;//advances d and q counter for each for loop iteration
	q++;
}
fout.close();


  



return 0;
}
//Pre: excepts integer more than 1
//Post: returns bool value (false if not prime... true if prime)
bool isPrime(int num)
 {
  int j;
  for(j = 2; j < num; j++) 
    if(num % j == 0) 
      return false;
  return true;
 }

