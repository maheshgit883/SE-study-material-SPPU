/* Write C++ program using STL to add binary numbers (assume one bit as one number); use
STL stack.
ROLL NO.:
BATCH:
DATE:
*/

#include<iostream>
#include<stack>	//Stacks are a type of container adaptor, specifically designed to operate in a LIFO context.

using namespace std;

stack <int> read();				//member function declaration
void display(stack<int> &s);			//display total stack
stack <int>add(stack<int> &s1,stack<int> &s2); //address of bit 1 and 0

int main()
{
	stack<int> s1,s2,s3;	//varible declartion for individual bit 1, 0 and addition
	int ch;

	do
	{
		cout<<"\n1.Addition of two binary numbers\n2.Quit";
		cout<<"\nEnter your choice:";
		cin>>ch;

		switch(ch)
		{
		case 1: s1=read();	//read first bit
			s2=read();	//read second bit
			s3=add(s1,s2);	//add first and second bit
			display(s3);	//display addition of first and second
			break;
		}
	}while(ch!=2);
	return 0;
}

stack<int> read()
{
char a[40];	
stack<int> s;				//stack object created
cout<<"\n Enter a binary number: ";
cin>>a;
	for(int i=0;a[i]!='\0';i++)
	{
	if(a[i]=='1')			//adding binary 1 and 0 into stack
	s.push(1);
		else
		if(a[i]=='0')
		s.push(0);
	}
return s;
}

stack<int> add(stack<int> &s1,stack<int> &s2)
{
	stack<int> s;
	int sum,carry=0,bit1,bit2;		//variable declaration
	while(!s1.empty() || !s2.empty())
	{
		bit1=bit2=0;
		if(!s1.empty())
		{
			bit1=s1.top();
			s1.pop();		//remove the item from top
		}
		if(!s2.empty())
		{
			bit2=s2.top();
			s2.pop();		//remove the item from top
		}
		sum=(bit1+bit2+carry)%2;
		carry=(bit1+bit2+carry)/2;
		s.push(sum);			//add the item sum from top
	}

	if(carry==1)
		s.push(1);
	return s;
}
	
void display(stack<int> &s)
{
	cout<<"\n Sum= ";

	while(!s.empty())
	{
		cout<<s.top();
		s.pop();			//remove the item from top		
	}
}

/*OUTPUT

1.Addition of two binary numbers
2.Quit

Enter your choice:1

 Enter a binary number: 1010101011

 Enter a binary number: 1110001011

 Sum= 11000110110

1.Addition of two binary numbers
2.Quit

Enter your choice:2
*/
