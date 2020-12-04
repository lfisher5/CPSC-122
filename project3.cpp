/*
Class: CPSC 122 - 02
Team Member: Lauren Fisher
Submitted by: Lauren Fisher
GU Username: lfisher5
FileName: project3.cpp
Program illustrates file, char, hash tables/arrays, and string manipulations
To build: g++ project3.cpp
To execute: ./a.out infile outfile MIfile action alpha beta
*/


#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> //need for EXIT_FAILURE

using namespace std;

void fileOpen(fstream&, char[], char);
char transform(char ch, int action, int alpha, int beta, int MI);
int getMI(int alpha, int array[][2]);

int main(int argc, char* argv[]) 
{

	fstream fout;
	fstream fin;
	fstream fin2;
	char ch;
	int i, j; 
	int MI;
	int alpha = atoi(argv[5]);
	int beta = atoi(argv[6]);
	int action = atoi(argv[4]);
	int MIarray[25][2];
	
	if(atoi(argv[5]) % 2 == 0) 
	{
		cout << "Alpha must be odd!" << endl;
		exit(-1);
	}

	if(argc != 7)
	{
		cout << "Incorrect # of command line arguments" << endl;
		exit(EXIT_FAILURE);
	}

	fileOpen(fin, argv[1], 'r');
	fileOpen(fout, argv[2], 'w');
	fileOpen(fin2, argv[3], 'r');
	
	for(int i = 0; i < 25; i++) //rows
	{
		for(int j = 0; j < 2; j++) //columns
		{
			fin2 >> MIarray[j][i];  //switched j and i
		}
	}
	
	MI = getMI(alpha, MIarray);
	
	while(fin.peek() != EOF) 
	{
		ch = fin.get();//gets each character individually
		if (isalpha(ch))//if is in alphabetic range
		{
			ch = toupper(ch);
			ch = transform(ch, action, alpha, beta, MI);
		}
		fout.put(ch);
	}

	
	fin.close();
	fout.close();
	fin2.close();

return 0;
}

//Pre: file, array, and mode of fstream
//Outputs: opens files
void fileOpen(fstream& file, char arr[], char mode) 
{
	string fileType;
	
	if (mode == 'r')
  		fileType = "input";
	if (mode == 'w')
  		fileType = "output";

	if (mode == 'r')
  		file.open(arr, ios::in);  //available thorugh fstream
 	if (mode == 'w')
  		file.open(arr, ios::out);  //available through fstream;

 	if (file.fail()) //error condition 
 	{
  		cout << "Error opening " << fileType << " file" << endl; 
  		exit(EXIT_FAILURE);
 	}
}

//Pre: character, action (0 or 1), alpha (CL), beta (CL), MI
//Post: character transformed
char transform(char ch, int action, int alpha, int beta, int MI)
{
	int num;
	
	num = static_cast<int>(ch) - 65;//puts number in range 0 - 25
	
	if(action == 0) //encrypt
	{
		num = (alpha * num + beta) % 26;	
	}
	else //decrypt
	{
		num = ((MI * num - (MI * beta))) % 26;
	}	
	
	ch = static_cast<char>(num) + 65; //goes back to char value
	//cout << ch;
	
	return ch;
	
}	

//Pre: alpha and integer array
//Post: integer Multiplicative inverse
int getMI(int alpha, int array[][2])
{
	int i, j, MI;
	int ct = 0;
	
	for(i = 0; i < 25; i++) //rows
	{
		for(j = 0; j < 2; j++) //columns
		{
			if(ct == alpha) 
			{
			MI = array[j][i];
			}
			ct++;
		}
	}
	return MI;
}

	

