#include <iostream>
using namespace std;

#include "project6.h"


int main()
{
 //static list
 /*
 List lst;
 cout << "print list" << endl;
 for (int i = 0; i < 5; i++)
   lst.PutItemH(i);
 lst.Print();
 cout << "print head" << endl;
 cout << lst.GetItemH() << endl;
 lst.DeleteItemH();
 cout << "print again" << endl;
 lst.Print();
*/
 //dynamic list
 List* lst1 = new List;
 //cout << lst1->IsEmpty();
 for (int i = 0; i < 5; i++)
  lst1->PutItemH(10*i);
  lst1->Print();
  //cout << endl << lst1->GetItemH();
  lst1->~List();
  //cout << endl << lst1->Find(10);
  //lst1 -> DeleteItem(2);
  //cout << endl;
  //lst1->Print();
 //cout << lst1->IsEmpty();
 //lst1->Print();
 //cout << lst1->GetLength() << endl;
 //lst1 -> DeleteItemH();
 //lst1 -> Print();
 //cout << lst1->GetLength();

 delete lst1; //necessary to invoke destructor on dynamic list
 
 return 0;
}
