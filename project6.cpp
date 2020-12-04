/*
Class: CPSC 122 - 02
Team Member: Lauren Fisher
Submitted by: Lauren Fisher
GU Username: lfisher5
FileName: project6.cpp
Program illustrates dynamic allocation of memory and linked lists
To build: g++ project3.cpp project6Tst.cpp
To execute: ./a.out 
*/
#include <iostream>
using namespace std;
 
#include "project6.h"

List::List()//constructor
{  
	head = NULL;
	length = 0;
}

List::~List()//deconstructor
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

bool List::IsEmpty() const
{

	node* tmp = head;
	if(tmp == NULL)
		return true;
	else 
		return false;

}


int List::GetLength() const
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

void List::PutItemH(const itemType newItem)
{
	node* tmp = new node;
	tmp -> item = newItem;
	tmp -> next = head;
	head = tmp;
	length++;
	tmp = NULL;

}

itemType List::GetItemH() const
{

	itemType item;
	node* tmp = head;
	item = tmp -> item;//item set to whatever head points to
	

 return item; 
}

void List::DeleteItemH()
{

node* tmp = head -> next;//points tmp one past head pointer
delete head;
head = tmp;
tmp = NULL;
length--;//must change length

}
	
void List::Print() const//works
{

	node* tmp = head;
	while(tmp != NULL)
	{
		cout << tmp -> item << " ";
		tmp = tmp -> next;//increment
	}

}

int List::Find(const itemType item) const
{
	
	int pos = 0;
	node* tmp = head;
	
	while((tmp != NULL) && (tmp->item != item))
	{
		tmp = tmp -> next;
		pos++;
	}
	if(tmp -> item == item)
		return pos-1;//base 0 position
	else
		return -1;

}


void List::DeleteItem(const int pos)
{

	node* tmp = head;
	int i = 0;
	
	if(pos == 0)
	{
		DeleteItemH();//deletes head
		return;
	}
	
	while(tmp != NULL)
	{
		tmp = tmp -> next;
		i++;
		
		if(i == pos-1)
		{
			node* tmp2 = tmp->next;//points tmp2 one past tmp
			tmp -> next = tmp -> next-> next;//skips over deleted item
			delete tmp2;//deletes item
			tmp2 = NULL;
			tmp = NULL;
			length--;
			break;
		}	
		
	}


}
