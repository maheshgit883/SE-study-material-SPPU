/*
B-16
Title: Write a C++ program that creates an output employee, writes information to it, closes the employee and open it again as an input employee and read the information from the employee.

*/

#include <iostream> //standard input output sream header file
#include <fstream> //for reading and wrinting purpose
 
using namespace std;

class employee //name of employee class
{
char name[20]; //variable declaration
int emp_id;
float salary;
public:
	void accept() //member function declaration
	{
	cin>>name;
	cin>>emp_id;
	cin>>salary;
	}

	void display()
	{
	cout<<"\n"<<name<<"\t"<<emp_id<<"\t"<<salary;
	}
};

int main()
{
employee o[5];
fstream f;
int i,n;

f.open("input.txt");				//create employee
cout<<"\n How many employee information wanted to store:";
cin>>n;
//How many employee information wanted to store:3
cout<<"\n Enter information of employees (Enter name, emp_id, salary)";
	for(i=0;i<n;i++)
	{
	cout<<"\n Enter information of "<<i<<" employee";
	o[i].accept();				//accept input from user
	f.write((char *)&o[i], sizeof(o[i]));	//write object in employee
	}	
f.close();

f.open("input.txt", ios::in);
cout<<"\n Information of employee is as follows";
	for(i=0;i<n;i++)
	{
	f.read((char*)&o[i], sizeof(o[i]));	//read data from employee
	o[i].display();
	}
f.close();

return 0;

}

/*OUTPUT
srl@srl-Lenovo-G550:~/Desktop/OOPL$ g++ b16.cpp
srl@srl-Lenovo-G550:~/Desktop/OOPL$ ./a.out

 How many employee information wanted to store:3

 Enter information of 3 employees (Enter name, emp_id, salary)
 Enter information of 0 employeea
1
100

 Enter information of 1 employeeb
2
200

 Enter information of 2 employeec
3
300

 Information of employee is as follows
a	1	100
b	2	200
c	3	300
*/
