#include <iostream>
using namespace std;

#include "project7.h"


int main()
{
 
List1 lst;

	
 for (int i = 0; i < 5; i++)
   lst.PutItemT(i);

   cout << "original:" << endl;
 lst.Print();
 cout << "updated:" << endl;
 cout << "DeleteItem: " << endl;
 lst.DeleteItem(2);
 lst.Print();

 //delete lst1; //necessary to invoke destructor on dynamic list
 
 return 0;
}
