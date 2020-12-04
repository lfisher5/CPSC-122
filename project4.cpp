/*
Class: CPSC 122-01
Paul De Palma
GU Username: lfisher5
Submitted By: Lauren Fisher
File Name: project4.cpp 
Program reads an inp;ut file into an array
        sorts the input file using selection sort 
        writes the sorted array to an output file 
To Build: g++ project4.cpp 
To Execute: ./a.out emily out # of lines
*/

#include <iostream>
#include <fstream> 
#include <string>
#include <cstdlib>
using namespace std;

const int SIZE = 9;
void fileOpen(fstream&, char[], char);
void readData(fstream&, char[], string[], int);
void writeData(fstream&, char[], string[], int);
//write these three functions
void selSort(string[], int);
int findSmallest(string[], int, int);
void swap(string[], int, int);

int main(int argc, char* argv[])
{
 fstream fin;
 fstream fout;
 string line;
 int size = atoi(argv[3]);//size of array from command line
 string* data = new string [size];//dynamically allocate memory 


 if (argc != 4)
  { 
   cout << "Incorrect number of command line arguments" << endl;
   exit(EXIT_FAILURE);
  }

 readData(fin, argv[1], data, size);//read from file into array

 selSort(data, size);//sort file

 writeData(fout, argv[2], data, size);//write sorted array to file
 
 return 0;
}

//Pre: takes input file
//Post: reads file into an array of strings
void readData(fstream& file, char fileName[], string data[], int size)
{
 fileOpen(file, fileName, 'r');
 for (int i = 0; i < size; i++)
 {
  	getline(file,data[i]);
 }
 	file.close();
}

//Pre: takes array and output file name
//Post: creates file of name specified and writes new array to it
void writeData(fstream& file, char fileName[], string data[], int size)
{
 fileOpen(file, fileName, 'w');
 for (int i = 0; i < size; i++)
 {
 	file << data[i] << endl;
 	
 }
 file.close();
}

//takes name of file and mode of file
//reads or writes to file of name specified 
void fileOpen(fstream& file, char name[], char mode)
{
 string fileType;

 if (mode == 'r')
  fileType = "input";
 if (mode == 'w')
  fileType = "output";

 if (mode == 'r')
  file.open(name, ios::in);  //available thorugh fstream
 if (mode == 'w')
  file.open(name, ios::out);  //available through fstream;

 if (file.fail()) //error condition 
 {
 cout << "Error opening " << fileType << " file" << endl; 
 exit(EXIT_FAILURE);
 }
}

/*
Pre:  data is an array of strings
Post: data is in sorted order
*/
void selSort(string data[], int size)
{
 
 int idxSmallest;
 
 for(int cur = 0; cur < (size-1); cur++)
 {
 	idxSmallest = findSmallest(data, cur, size);
 	
 	swap(data, cur, idxSmallest);//swap cur with smallest
 	
 }
 
}

/*
Pre:  data is an arrray of strings, cur begins the subarray under consideration
Post: returns the smallest item in the array, beginnig with cur
*/
int findSmallest(string data[], int cur, int size)
{

	int idxSmallest = cur;
	for(int i = cur+1; i < (size); i++)
	{
		if(data[i] < data[idxSmallest])
		{
			idxSmallest = i;
		}
	}
 //starting with cur, find the index of the smallest item in the array
 //return the index of the smallest item in the array
 return idxSmallest;
}


/*
Pre:  data is an arrray of strings, cur and idxSmallest are indices 
Post: what was in postion cur is now in position idxSmallest and vice-versa 
*/
void swap(string data[], int cur, int idxSmallest)
{
	string num;

	num = data[cur];//stored in temp var
	data[cur] = data[idxSmallest];
	data[idxSmallest] = num;

}
