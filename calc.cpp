#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
using namespace std;

#include "calc.h"

Calc::Calc(int argcIn, char* argv[])
{

	
	inFix = new char[strlen(argv[1])+1]; 
	postFix = new char[strlen(argv[1])+1]; 
	hashTble = new int[26];
	
	
	strcpy(inFix, argv[1]);

	
	int j = 2;
	for(int i = 0; i < strlen(argv[1]); i++)
	{
		
		if(isupper(inFix[i]))
			{
				int num = inFix[i] - 65;
				hashTble[num] = atoi(argv[j]);
				j++;
			}
	}
	
	
	
	if(!CheckTokens())
	{
		cout << "Illegal tokens"<< endl;
		exit(-1);
	}
	if(!CheckParens())
	{
		cout << "Parentheses not balanced" << endl;
		exit(-1);
	}




}




Calc::~Calc()
{


delete stk;
delete inFix;
delete postFix;
delete hashTble;



}

bool Calc::CheckTokens()//Good
{
	for(int i = 0; i < strlen(inFix); i++)
	{
		if(!isupper(inFix[i])&&!IsOp(inFix[i]))
			return false;
	}		
	return true;
}

bool Calc:: IsOp(char ch)
{
	if(ch == '(')
		return true;
	if(ch == ')')
		return true;
	if(ch == '+')
		return true;
	if(ch == '-')
		return true;	
	if(ch == '*')
		return true;
	if(ch == '/')
		return true;	
	
	return false;	

}

bool Calc::CheckParens()
{
int i = 0;

	stk = new Stack;
	
	for(int i = 0; i < strlen(inFix); i++)
	{
		if(inFix[i] == '(')
			stk->Push(inFix[i]);
			else
				if(inFix[i] == ')')
					if(stk->IsEmpty())
						return false;
			else
				stk->Pop();			
			
		
	}		
	
	if(stk->IsEmpty())
		return true;
	else 
		return false;
				
		delete stk;		
}
	

void Calc::DisplayInFix()
{
	cout << inFix << endl;
}

void Calc::DisplayPostFix()
{
	cout << postFix << endl;
}

void Calc::InFixToPostFix()
{


	int i = 0;
	int j = 0;
	while(inFix[i] != '\0')
	{
		if(isupper(inFix[i]))
		{
			postFix[j] = inFix[i];
			j++;
		}	
			
		else if(inFix[i] == '(')
		{
			
		}	
	
		else if(inFix[i] == ')')
		{
			char a = static_cast<char>(stk->Peek());
			postFix[j] = a;
			
			stk->Pop();
			j++;
			
		}
		else if(IsOp(inFix[i]))
		{
			//cout << inFix[i];
			stk->Push(inFix[i]);
		}	
		i++;	
		
		
	}
	postFix[i] = '\0';

}

void Calc::Evaluate()
{
	int i = 0;
	int j = 0;
	int op1;
	int op2;
	int Res;
	
	while(postFix[i] != '\0')
	{
		if(isupper(postFix[i]))
			stk->Push(postFix[i]);
		else
		{
			op2 = static_cast<int>(stk->Peek());
			stk->Pop();
			
			op1 = static_cast<int>(stk->Peek());
			stk->Pop();
			
			if(op2 > 64)
			{
				op2 -= 65;
				op2 = hashTble[op2];
			}
			if(op1 > 64)
			{
				op1 -= 65;
				op1 = hashTble[op1];
			}
				
			if(postFix[i]== '+') 
				Res = op1 + op2;
			if(postFix[i]== '-') 
				Res = op1 - op2;
			if(postFix[i]== '*' )
				Res = op1 * op2;
			if(postFix[i]== '/')	
				Res = op1 / op2;
				
		
			stk->Push(Res);
			
			
		}		
	i++;
	
	
	
	}
	cout << "Result: " << stk->Peek() << endl;
	


}




