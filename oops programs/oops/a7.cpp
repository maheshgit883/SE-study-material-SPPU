/*=======================================================================
Assignment no : A7
Title	      : Implement C++ program to write a class template to represent a generic
		vector. Include following member functions:
		To create the vector.
		To modify the value of a given element
		To multiply by a scalar value
		To display the vector in the form (10,20,30,...)
CLASS	      :
Batch	      : 
ROLL NO	      :	
Date	      :  
=======================================================================*/
#include<iostream> //header file
#include<vector>
using namespace std; //declared scope of program
void display (vector<int>&v) //function declaration
{
	for(int i=0;i<v.size();i++)
	{
		cout<<"   "<<v[i];
	}
	cout<<" \n";
}
int main()
{
	vector<int> v;
	cout<<"\n Initial Size: "<<v.size();
	int x;
	cout<<"\n Enter The 5 Element: ";
	for(int i=0;i<5;i++)
	{
		cin>>x;
		v.push_back(x);
	}
	cout<<"\n Size After Insertion: "<<v.size();
	cout<<"\n Vector Element: ";
	display(v);
	cout<<"\nVector Element After insertion of 3 at End of Vector: ";
	v.push_back(3);
	display(v);
	vector<int>::iterator itr=v.begin(); 
	itr=itr+3;
	v.insert(itr,9);
	cout<<"\n Content After Insertion 9 at position 3rd: ";
	display(v);
	v.erase(v.begin()+3,v.begin()+5);
	cout<<"\n After Erasing(3rd-4th position): ";
	display(v);
}

/*--------------------------OUTPUT--------------------------------------
gescoe@gescoe-OptiPlex-3010:~/Desktop/se$ g++ fifth.cpp
gescoe@gescoe-OptiPlex-3010:~/Desktop/se$ ./a.out

 Initial Size: 0
 Enter The 5 Element: 6 9 4 2 1

 Size After Insertion: 5
 Vector Element:    6   9   4   2   1 

 Vector Element After insertion of 3 at End of Vector:    6   9   4   2   										1   3 

 Content After Insertion 9 at position 3rd:    6   9   4   9   2   1   3 

 After Erasing(3rd-4th position):    6   9   4   1   3 

-----------------------------------------------------------------------*/

