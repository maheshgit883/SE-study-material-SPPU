/*
Crete User defined exception to check the following conditions and throw the exception if the
criterion does not meet.
a. User has age between 18 and 55
b. User has income between Rs. 50,000 – Rs. 1,00,000 per month
c. User stays in Pune/ Mumbai/ Bangalore / Chennai
d. User has 4-wheeler
Accept age, Income, City, Vehicle from the user and check for the conditions mentioned
above. If any of the condition not met then throw the exception.
*/

#include<iostream> //standard input output header file
#include<stdexcept> //for handling exception
#include<typeinfo> //for variable datatype identification
#include<string> //string comparison purpose
#include<cstring> //for string manipulation in c/c++ for various fun. and array

using namespace std;

int main()
{
int i,n,age;	//variable declaration
char car;
double income;
char city[20];

cout<<"\n Enter Age of person:";
cin>>age;
	try
	{
	if(age<18||age>55)	
	throw runtime_error("\n Age is not between 18-55");
	}
	catch(const exception& e)
		{
		cout<<"Caught exception:"<<e.what()<<'\n';
		}

cout<<"\n Enter income of person:";
cin>>income;
	try
	{
	if(income<50000||income>100000)	
	throw runtime_error("\n Income is not int the range of 50000-100000");
	}
	catch(const exception& e)
		{
		cout<<"Caught exception:"<<e.what()<<'\n';	
		}

cout<<"\n Enter city of person:";
cin>>city;
	try
	{
	if(strcmp(city, "Pune")&& strcmp(city, "Banglore")&& strcmp(city,"Chennai")&& strcmp(city, "Mumbai"))	
	throw runtime_error("\n Person is not staying in Pune/Mumbai/Banglore/Chennai");
	}
	catch(const exception& e)
		{
		cout<<"Caught exception:"<<e.what()<<'\n';
		}

cout<<"\n Whether person holds car or not? (y/n):";
cin>>car;	
	try
	{
	if(car=='n')
	throw runtime_error("\n Person should hold car");
	}
	catch(const exception& e)
		{
		cout<<"Caught exception:"<<e.what()<<'\n';
		}

cout<<"\n Information of person is as follows:";
cout<<"\n Age:"<<age;
cout<<"\n Income:"<<income;
cout<<"\n Location:"<<city;
cout<<"\n Holding car or not?:"<<car;

return 0;
}

/*OUTPUT
srl@srl-Lenovo-G550:~/Desktop/OOPL$ g++ b14.cpp
srl@srl-Lenovo-G550:~/Desktop/OOPL$ ./a.out

 Enter Age of person:43

 Enter income of person:56000

 Enter city of person:Chennai

 Whether person holds car or not? (y/n):y

 Information of person is as follows
 Age:43
 Income:56000
 Location:Chennai
 Holding car or not?:y
*/
