/*
Class: CPSC 122 - 02
Team Member: Lauren Fisher
Submitted by: Lauren Fisher
GU Username: lfisher5
FileName: project2.cpp
Program illustrates file, char, and string manipulation.
To build: g++ project2.cpp
To execute: ./a.out infile outfile action shift
*/



#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char transform(char, int, int);

int main(int argc, char* argv[]) 
{

string line;
ofstream fout;
ifstream fin;
int i = 0;
char ch;
int action = atoi(argv[3]);//command line arg to int
int shift = atoi(argv[4]);

fin.open(argv[1]);
fout.open(argv[2]);


while(fin.peek() != EOF) //goes through entire file
{
	ch = fin.get();//gets each character individually
	if (isalpha(ch))//if is in alphabetic range
	{
		ch = toupper(ch);//uppercase transform
		ch = transform(ch, action, shift);//encrypt / decrypt transform
	}
	fout.put(ch);//writes charcter to ouptut file
}		


fin.close();
fout.close();

return 0;
}


//Pre: accepts a char character, action 0 or 1 and a shift between 1-25
//Post: returns an encrypt/decrypt char dependent upon action

char transform(char ch, int action, int shift) 
{
	int num;
	
	num = static_cast<int>(ch) - 65;//puts number in range 0 - 25
	
	if(action == 0) //encrypt
	{
		num = (num + shift) % 26;	
	}
	else //decrypt
	{
		num = ((num - shift) + 26) % 26;
	}	
	
	ch = static_cast<char>(num) + 65; //goes back to char value
	//cout << ch;
	
	return ch;
}	
	

	
	
	
	
	
	
	
	
