// Write C++ program using STL for implementation of queue using SLL

#include<iostream>
#include<string.h>
#include<list>
using namespace std;

class Queue
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
			cout<<"\n The elements in the queue are : "<<"\n";
			for(itr=s.begin() ; itr!=s.end() ; itr++)
			{
				cout<<*itr<<"\t";
			}
		}

		void pop()
		{
			itr=s.begin();
			s.pop_front();
			cout<<"\n The element popped out of the queue is "<<*itr;
		}

};

int main()
{
	Queue p;
	int choice;
	char ans;
	do
	{
		cout<<"\n 1. Add element \n 2. Delete element \n 3. Display queue elements";
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


