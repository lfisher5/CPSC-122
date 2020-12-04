/*
Class: CPSC 122-01
Paul De Palma
GU Username: lfisher5
Submitted By: Lauren Fisher
File Name: project8.cpp 
Program reads is a class for a linkedlist and performs various functions on it
To Build: g++ project8.cpp project8Tst.cpp
To Execute: ./a.out 
*/
#include <iostream>
#include <climits>
using namespace std;

#include "project8.h"

   
List2::List2()//good
{
 length = 0;
 
//create dummy nodes;
 head = new doubleNode;
 tail = new doubleNode;

 //set values for head dummy node;
 head->prev = NULL;
 head->item = INT_MIN;
 head->next = tail;

 //set values for tail dummy node;
 tail->prev = head; 
 tail->item = INT_MAX;
 tail->next = NULL;
}


List2::List2(List2* lst)
{
	 length = 0;
 
//create dummy nodes;
 head = new doubleNode;
 tail = new doubleNode;

 //set values for head dummy node;
 head->prev = NULL;
 head->item = INT_MIN;
 head->next = tail;

 //set values for tail dummy node;
 tail->prev = head; 
 tail->item = INT_MAX;
 tail->next = NULL;
 
 doubleNode* cur = new doubleNode;
 cur = head;
 doubleNode* tmp = new doubleNode;
 tmp = lst->head->next;
 while(tmp != lst->tail)
 {
 	doubleNode* insert = new doubleNode;
 	insert->item = tmp->item;
 	insert->next = tail;
 	insert->prev = cur;
 	cur->next = insert;
 	tail->prev = insert;
 	cur = cur->next;
 	tmp = tmp->next;
 	length++;
 
 }
 
 cur = NULL;
 tmp = NULL;
 




}

List2::~List2()//good
{

	doubleNode* tmp = head;
	while(tmp->next != 0)
	{
		doubleNode* tmp2 = tmp->next;
		tmp->next = tmp2->next;
		delete tmp2;
		length--;
	}	

}

doubleNode* List2::FindPosition(int pos)//good
{
 doubleNode* cur = head;
 int i = 0;
 while (i < pos - 1)
 {
  cur = cur->next;
  i++;
 }
 return cur;
} 
  
void List2::Insert(itemType item, int pos)//good
{
 //new node goes between these two nodes
 doubleNode* insertPtA = FindPosition(pos);  
 doubleNode* insertPtB = insertPtA->next; 

 //create new node and set its values
 doubleNode* tmp = new doubleNode; 
 tmp->prev = insertPtA;
 tmp->item = item;
 tmp->next = insertPtB;

 //set pointers for the previous and next nodes
 insertPtA->next = tmp;
 insertPtB->prev = tmp;

 length++;
}

void List2::Delete(int pos)//good
{

doubleNode* tmp= FindPosition(pos);//before deleted node
doubleNode* tmp2= tmp->next;//after deleted node
tmp->next=tmp->next->next;//skips over node to be deleted
delete tmp2;
tmp = NULL;
tmp2 = NULL;
length--;

}


int List2::DeleteAll(itemType item)//good
{
	int i = 0;
	doubleNode* tmp = head;
	while(tmp->next != tail)
	{
		doubleNode* tmp2 = tmp->next;
		
		if(tmp->next->item == item)
		{
		doubleNode* tmp2 = tmp->next;
		tmp->next = tmp->next->next;//skips over node
		delete tmp2;
		i++;//number of deletes
		length--;
		tmp = tmp->prev;//idk why i needed this I just do
		}
		tmp = tmp->next;//increment
	}	
	return i;

}

void List2::PrintForward()//good
{
 doubleNode*  cur = head->next;

 int i = 0;
 while (i < length)
 {
  cout << cur->item << endl;
  cur = cur->next;
  i++;
 }
}
 
void List2::PrintBackwards()//good
{
 doubleNode* cur = tail->prev;

 int i = 0;
 while (i < length)
 {
  cout << cur->item << endl;
  cur = cur->prev;
  i++;
 }
} 


void List2::Sort()
{
	doubleNode* tmp = head->next;
	itemType arr[length];
	int i = 0;
	
	while(i < length)
	{
		arr[i] = tmp->item;
		tmp = tmp-> next;
		i++;
	}
	//selection sort code:
	int idxSmallest;
 
 	for(int cur = 0; cur < (length-1); cur++)
 	{
 		idxSmallest = findSmallest(arr, cur);
 	
 		swap(arr, cur, idxSmallest);//swap cur with smallest
 	
 	}
 	
 	i = 0;
 	
 	while(i < length)
 	{
 		//Delete(i);//deletes everything from list
 		Insert(arr[i], i);//inserts array into linked list

		i++;
		
 	}

	
}



int List2::findSmallest(itemType arr[], int cur)
{

	int idxSmallest = cur;
	for(int i = cur+1; i < length; i++)
	{
		if(arr[i] < arr[idxSmallest])
		{
			idxSmallest = i;
		}
	}
 //starting with cur, find the index of the smallest item in the array
 //return the index of the smallest item in the array
 return idxSmallest;
}

void List2::swap(itemType arr[], int cur, int idxSmallest)
{
	itemType num;

	num = arr[cur];//stored in temp var
	arr[cur] = arr[idxSmallest];
	arr[idxSmallest] = num;

}


