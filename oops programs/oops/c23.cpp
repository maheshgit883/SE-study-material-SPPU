/*
Write C++ program using STL for Dqueue (Double ended queue)
ROLL NO.:
BATCH:
DATE:
*/

#include<deque>		// Header that defines the deque container class
#include<stdio.h>	//standard input output header file
#include<iostream>	//standard input output stream header file

using namespace std;

int main()
{
	deque <int>dq;		//creates deque
	deque <int>::iterator p;//iterator is an object that enables a programmer to traverse contents of container
        char cc;
        int val,ch;
	 do
	   {
	   cout<<"\n\nMENU:";
	   cout<<"\n1. Enter element at front\n2. Enter element at Rear\n3. Delet element at front\n4. Delet element at Rear\n5. Display front element\n6. Display back element\n7. Display the element of Deque\n\n";
	   cout<<"\nEnter choice:";
	   cin>>ch;
	   switch(ch)
		   {
		   case 1:
		    cout<<"\n\nEnter the element to be inserted:";
		    cin>>val;
		    dq.push_front(val);		
		    cout<<"\nElement inserted at front:"<<dq.front();
		    break;

		   case 2:
                    cout<<"\n\nEnter the element to be inserted:";
	            cin>>val;
           	    dq.push_back(val);
		    cout<<"\nElement inserted at rear end:"<<dq.back();
		    break;

		   case 3:
	            cout<<"\nElement to be deleted at front:"<<dq.front();
		    dq.pop_front();
		    break;

		   case 4:
		   cout<<"\nElement to be deleted at rear:"<<dq.back();
		   dq.pop_back();
		    break;
		
		   case 5:
		   cout<<"\nElement at front:"<<dq.front();
		    break;
	
		   case 6:
		   cout<<"\nElement at rear:"<<dq.back();
		    break;

		   case 7:
		    if(dq.empty()==1)
                    cout<<"\n\nDEQUE is EMPTY..";
			else
			{
			cout<<"\n\nDisplaying the elements of DEQUE...\n";
			for(p=dq.begin();p<dq.end();p++)
			cout<<" "<<*p<<"\t";
			}
			 break;
		   }
                  cout<<"\n\nCONTINUE MENU:";		  
		  cin>>cc;
	          }while(cc=='y');
return 0;
}

/*
OUTPUT

MENU...
1. Enter element at front
2. Enter element at Rear
3. Delet element at front
4. Delet element at Rear
5. Disp front element
6. Disp back element
7. Display the element of deque

Enter choice:1

Enter the element to be inserted:1

Element inserted at front:1

CONTINUE MENU:y

MENU...
1. Enter element at front
2. Enter element at Rear
3. Delet element at front
4. Delet element at Rear
5. Disp front element
6. Disp back element
7. Display the element of deque

Enter choice:2

Enter the element to be inserted:2

CONTINUE MENU:y

MENU...
1. Enter element at front
2. Enter element at Rear
3. Delet element at front
4. Delet element at Rear
5. Disp front element
6. Disp back element
7. Display the element of deque

Enter choice:7

Displaying the elements of deque...

 1       2

CONTINUE MENU:y

MENU...
1. Enter element at front
2. Enter element at Rear
3. Delet element at front
4. Delet element at Rear
5. Disp front element
6. Disp back element
7. Display the element of deque

Enter choice:1

Enter the element to be inserted:0

Element inserted at front:0

CONTINUE MENU:y

MENU...
1. Enter element at front
2. Enter element at Rear
3. Delet element at front
4. Delet element at Rear
5. Disp front element
6. Disp back element
7. Display the element of deque

Enter choice:2

Enter the element to be inserted:3

Element inserted at rear end:3

CONTINUE MENU:y

MEMU...
1. Enter element at front
2. Enter element at Rear
3. Delet element at front
4. Delet element at Rear
5. Disp front element
6. Disp back element
7. Display the element of deque

Enter choice:7

Displaying the elements of deque...

 0       1       2       3

CONTINUE MENU:y

MENU...
1. Enter element at front
2. Enter element at Rear
3. Delet element at front
4. Delet element at Rear
5. Disp front element
6. Disp back element
7. Display the element of deque

Enter choice:5

Element at front:0

CONTINUE MENU:y

MENU...
1. Enter element at front
2. Enter element at Rear
3. Delet element at front
4. Delet element at Rear
5. Disp front element
6. Disp back element
7. Display the element of deque

Enter choice:6

Element at rear:3

CONTINUE MENU:y

MENU...
1. Enter element at front
2. Enter element at Rear
3. Delet element at front
4. Delet element at Rear
5. Disp front element
6. Disp back element
7. Display the element of deque

Enter choice:3

Elementto be deleted at front:0

CONTINUE MENU:y

MENU...
1. Enter element at front
2. Enter element at Rear
3. Delet element at front
4. Delet element at Rear
5. Disp front element
6. Disp back element
7. Display the element of deque

Enter choice:4

Element to be deleted at rear:3

MENU...
1. Enter element at front
2. Enter element at Rear
3. Delet element at front
4. Delet element at Rear
5. Disp front element
6. Disp back element
7. Display the element of deque

Enter choice:7

Displaying the elements of deque...

 1       2

CONTINUE MENU:n
*/
