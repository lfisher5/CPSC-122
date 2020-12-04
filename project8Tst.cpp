#include <iostream>
using namespace std;

#include "project8.h"


int main()
{
 List2* lst = new List2;
 
 for (int i = 0; i <= 5; i++)
   lst->Insert(i,i);

 lst->Insert(0,6);
 

 cout << "Front To Back" << endl;
 lst->PrintForward();

 //cout << "Back To Front" << endl;
 //lst->PrintBackwards();
 
 //lst->~List2();
 

 cout << "Deletes: " << lst->DeleteAll(0) << endl;
 //lst->Sort();
 cout <<"Delete:"<< endl;
 lst->PrintForward();
 
 List2* lst1 = new List2(lst);
 cout << "List Copy: " << endl;
 lst1->PrintForward();
 return 0;

}
