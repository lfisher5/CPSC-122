#include <iostream>
using namespace std;

#include "project5.h"

//Constructor function
MyString::MyString(char const* strIn)
{
 //determine the length of MyString instance
 length = 0;
 while(strIn[length] != '\0')
  length++;

 //dynamically allocate memory for MyString instance
 str = new char[length + 1];

 //copy contents of strIn to MyString instance
 int i = 0;
 while(i < length)
 {
  str[i] = strIn[i];
  i++;
 }
 str[i] = '\0';
}

//Destructor function
MyString::~MyString()
{
 delete [] str;

}

void MyString::myDisplay()
{
 for (int i = 0; i < length; i++)
  cout << str[i];
 cout << endl;
}



/*
   Pre:  An instance of MyString exists whose length <= length of strIn
   Post: The contents of strIn overwrites the contents of the instance
         of MyString pointed to by the member variable str.  str is 
	 terminated by the null character.   
*/
void MyString::myStrcpy(char const* strIn)  
{

	int i = 0;
	str = new char[length + 1];//dynamically allocates memory
	
	while(strIn[i] != '\0')
	{
		str[i] = strIn[i];
		
		i++;
	}	
	str[i] = '\0';
	
}


/*
   Pre:  An instance of MyString exists
   Post: Returns the number of characters, excluding the null character
         in MyString. 
*/
int MyString::myStrlen()  
{


	return length;
}


/*
   Pre:  An instance of MyString exists. strIn is a null-terminated
         string.
   Post: Returns true if the strings are equivalent, false otherwise 
*/
bool MyString::isEqual(char const* strIn)
{
int truth = 0;
	
	for(int i = 0; i < length; i++)
	{
		if(strIn[i] == str[i])
		{
			truth++;
		}
	}
	if (truth == length)
	{
		return true;//if number of the same characters is equal to the length
	}
	else
	{
		return false;
	}
}


/*
   Pre:  An instance of MyString exists
   Post: If strIn is a substring of the instance of MyString, returns
         the index of its starting positon, -1 otherwise
*/
int MyString::find(char const* strIn)
{
	int length2 = 0;
	int i = 0;
	int j = 0;
	int truth;
	while(strIn[i] != '\0')
	{
		length2++;
		i++;
	}
	for(i = 0; i < length; i++)
	{
		if(str[i] == strIn[0])
		{
			truth = 0;//must be zero when it enters the below if-statement
			for(j = 0; j < length2; j++)
			{
				truth++;//substring == string
				if(truth == length2)
					return i;//returns index
			}
		}	
	}
	return -1;//returns -1 otherwise

}


/*
   Pre:  An instance of MyString exists. strIn is a null-terminated string
   Post: strIn is concatenated with the instance of MyString.  Ex.
         MyString is ABC. strIn is DEF.  MyString is still a null-terminated
	 string, but contains: ABCDEF. 
*/
void MyString::concat(char const* strIn)
{
	int length2 = 0;//length for input string
	
	while(strIn[length2] != '\0')
		length2++;
		
	char* str1 = new char[length + length2 + 1];//sets new size for new string
	
	for(int i = 0; i < length; i++)
		str1[i] = str[i];//copies first string in
	
	int i = 0;
	while(strIn[i] != '\0')
		{
		str1[length+i] = strIn[i];//copies 2nd string starting at length+1 of first string
		i++;
		}
		
	

	str[i]= '\0';//sets NULL character
	delete [] str;//delets what string points to
	str = str1;//sets str equal tp str1
	length = length + length2;//re increment length
	
	
}	

int MyString::FindChar(char ch)
{
	
	int i  = 0;
	
	for (int i = 0; i < length; i++)
	{
		if(str[i] == ch)
			return i;
	
	}
	return -1;


}
	
	
	
	





