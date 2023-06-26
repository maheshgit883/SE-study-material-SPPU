
//  Write C++ program using STL for implementation of stack using SLL

#include<iostream>
#include<string.h>
#include<list>
using namespace std;

class Stack
{
	public :
		int a;
		list <int> s;
		list <int> :: iterator itr;


		void push()
		{
			cout<<"\n Enter a number : ";
				cin>>a;
				s.push_back(a);
		}

		void displaystack()
		{
			cout<<"\n The elements in the stack are : "<<"\n";
			for(itr=s.begin() ; itr!=s.end() ; itr++)
			{
				cout<<*itr<<"\t";
			}
		}

		void pop()
		{
			itr=s.end();
			itr--;
			s.pop_back();
			cout<<"\n The element popped out of the stack is "<<*itr;
		}

};

int main()
{
	Stack p;
	int choice;
	char ans;
	do
	{
		cout<<"\n 1. Add element \n 2. Delete element \n 3. Display stack elements";
		cout<<"\n Enter the operation you want to perform : ";
		cin>>choice;
		switch(choice)
		{
			case 1 : p.push();
			break;
			case 2 : p.pop();
			break;
			case 3 : p.displaystack();
			break;
		}
		cout<<"\n Do you want to perform any other operation ?";
		cin>>ans;
	}while(ans=='Y' || ans=='y');
}
