/*
Class: CPSC 122 - 02
Team Member: Lauren Fisher
Submitted by: Lauren Fisher
GU Username: lfisher5
FileName: project7.cpp
Program illustrates dynamic allocation of memory and linked lists
To build: g++ project7.cpp project7Tst.cpp
To execute: ./a.out 
*/
#include <iostream>
using namespace std;
 
#include "project7.h"

List1::List1()//DONE
{
	length = 0;
	head = NULL;
	tail = NULL;
}
   
   
List1::~List1()//DONE
{

	while(head != NULL)
	{
		node* tmp = head -> next;
		delete head;
		head = tmp;
		tmp = NULL;
		length--;
	}
	

}


bool List1::IsEmpty() const//DONE
{

	node* tmp = head;
	if(tmp == NULL)
		return true;
	else 
		return false;

}


int List1::GetLength() const//DONE
{

	int i = 0;
	node* tmp = head;
	while(tmp != NULL)
	{
		i++;
		tmp = tmp -> next;
	}
	return i;

}


void List1::PutItemH(const itemType newItem)//DONE
{

	node* tmp = new node;
	tmp-> item = newItem;
	tmp-> next = head;
	head = tmp;
	if(length == 0)
		tail = tmp;
	tmp = NULL;
	length++;
	
}


itemType List1::GetItemH() const//DONE
{

	itemType item;
	node* tmp = head;
	item = tmp -> item;//item set to whatever head points to

	return item; 

}


void List1::DeleteItemH()//DONE
{
	node* tmp = head -> next;//points tmp one past head pointer
	delete head;
	head = tmp;
	tmp = NULL;
	length--;//must change length

}


void List1::PutItemT(const itemType newItem)//DONE
{
	
	if(length == 0)
	{
	PutItemH(newItem);
	return;
	}
	
	else
	{
		node* tmp = new node;
		tmp-> item = newItem;
		tail -> next = tmp;
		tail = tmp;
		tmp -> next = NULL;
		tmp = NULL;
		length++;
	}

}


itemType List1::GetItemT() const//DONE
{

itemType item;
	node* tmp = tail;
	item = tmp -> item;//item set to whatever head points to

	return item; 


}


void List1::DeleteItemT()//DONE
{

	node* tmp = head;
	while(tmp->next != tail)
		tmp = tmp->next; 
	tail = tmp;
	delete tmp->next;
	tmp->next = NULL;
	length--;
	tmp = NULL;

}


void List1::Print() const//DONE
{
	node* tmp = head;
	
	while(tmp != NULL)
	{
		cout << tmp -> item << endl;
		tmp = tmp -> next;//increment
	}

}
  

int List1::FindItem(const itemType target) const//DONE
{

	int i = 0;
	node* tmp = head;
	
	while(tmp != NULL)
	{
		if(tmp -> item == target)
			i++;
		tmp = tmp -> next;
	}	
	return i;


}


int List1::DeleteItem(const itemType target)
{

	node* tmp = head;
	int i = 0;
	
	
	while(tmp != NULL)
	{
		tmp = tmp -> next;
		
		if(tmp->next-> item == target)
		{
			node* tmp2 = ptrTo(target);//points tmp2 one past tmp
			tmp -> next = tmp -> next-> next;//skips over deleted item
			delete tmp2;//deletes item
			tmp = NULL;
			tmp2 = NULL;
			length--;
			i++;
		}	
		
	}
	return i;
}

node* List1::ptrTo(itemType target)
{
	node* tmp = head;
	while((tmp != tail) && (tmp->item != target))
	{
		if(tmp->item == target)
		{
			return tmp;
		}
	tmp = tmp->next;	
	
	}
	
	return NULL;



}


