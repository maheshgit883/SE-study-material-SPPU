/*
ASSIGNMENT NO:A-6
TITLE  :Develop an object oriented program in C++ to create a database of the personnel
	information system containing the following information: Name, Date of Birth, Blood
	group, Height, Weight, Insurance Policy number, Contact address, telephone number,
	driving license no. etc Construct the database with suitable member functions for
	initializing and destroying the data viz constructor, default constructor, copy,  		constructor, destructor, static member functions, friend class, this pointer, inline 		code and dynamic memory allocation operators-new and delete.
BATCH 	:
ROLL NO :
DATE	: 
==============================================================================================================================
*/
using namespace std;
#include<iostream>
#include<string.h> //for handling string eg.strcpy()
#include<ctime> //current date and time of system

class age;

class person
{
	friend class age;			//declared friend class age
	private:
		char *name,*blood,*address;	//declared data variable
		int dob;
		long int insurance,tel,license;
		float height,weight;
		static int count;               //static variables
	public:
		person()			 //default & dynamic constructor
		{
			count++;
			cout<<"-----------------default information------------";
			name=new char[13];	//allocate dynamic memory using new operator
			strcpy(name,"default name");
			blood=new char[3];
			strcpy(blood,"O+");
			address=new char[20];
			strcpy(address,"nasik");
			insurance=12345;
			tel=360410550;
			license=1234567;
			height=10.2;
			weight=120;
			dob=1996;
			display();

		}
		person(char n[],char b[],int yy,char add[],long int in,long int tn,long int ln,float h,float w) 
                                                            //parameterized constructor
		{
		        count++;
		        int len;
		        len=strlen(n);
		        name=new char[len+1];
		        strcpy(name,n);

		        len=strlen(b);
		        blood=new char[len+1];
		        strcpy(blood,b);

		        len=strlen(add);
		        address=new char[len+1];
		        strcpy(address,add);
		        dob=yy;
		        insurance=in;
		        tel=tn;
		        license=ln;
		        height=h;
		        weight=w;
		}
		void display();				//display function declaration
		
		person & compare(person *x1) 		//copy constructor
		{
			if(x1->height > height)
			{
			        return *x1;
			}
			else
			{
			        return *this;		//uses thin pointer
			}
		}
		static int displaycount()               //static member function
		{
		        cout<<"\n NUMBER OF ENTRIES ARE:"<<count<<endl;
		}

	        ~person()              	  //destructor having same name like constructor 
	        {
		        cout<<"\n destructor called...";
	        }
};
class age                                               //friend class defination
{
private:int ag,date;
public:
        void calculate(person *x)			//calculate the age of person
        {
                date=x->dob;
                time_t now=time(0);
                tm *ltm=localtime(&now);
                ag=(1900+ltm->tm_year)-date;
                cout<<" AGE:"<<ag<<endl;
        }
};
int person::count=0;
        void person::display()				//display function definition
        {
	        cout<<"\n PERSON NAME:"<<name;
	        cout<<"\n BLOOD GROUP:"<<blood;
	        cout<<"\n DATE OF BIRTH:"<<dob;
	        cout<<"\n CONTACT ADDRESS:"<<address;
	        cout<<"\n INSURANCE NUMBER:"<<insurance;
	        cout<<"\n TELEPHONE NUMBER:"<<tel;
	        cout<<"\n LICENSE NUMBER:"<<license;
	        cout<<"\n HEIGHT:"<<height;
	        cout<<"\n WEIGHT:"<<weight<<endl;
        }
int main()						//main function
{
	int ch;						//variable declaration
	person *p[20],*temp;
	age *a[20];
	char pname[15],pblood[5],paddress[20];
	long int pinsurance,ptel,plicense;
	float pheight,pweight;
	int cnt=0,dd;
do
{
        cout<<"\n ---------------------------MENU--------------------------"<<endl;
	cout<<"\n 1.DEFAULT CONSTRUCTER ";
	cout<<"\n 2.PARAMETERIZED CONSTRUCTOR";	
	cout<<"\n 3.NUMBER OF ENTRIES";
	cout<<"\n 4.CALCULATE AGE:";
	cout<<"\n 5.TALLER PERSON:";
	cout<<"\n 6.EXIT";
	cout<<"\n ENTER THE CHOICE:";
	cin>>ch;
	switch(ch)
	{
		case 1: 			//DEFAULT CONSTRUCTER INFORMATION
			p[cnt]=new person();
			a[cnt]=new age();
			cnt=cnt+1;
			break;
		case 2:				//PARAMETERIZED CONSTRUCTOR INFORMATION
			cout<<"\n ENTER THE PERSON NAME:";
			cin>>pname;
			cout<<"\n ENTER THE PERSON BLOOD GROUP:";
			cin>>pblood;
			cout<<"\n ENTER DATE OF BIRTH:";
			cin>>dd;
			cout<<"\n ENTER THE PERSON CONTACT ADDRESS:";
			cin>>paddress;
			cout<<"\n ENTER THE PERSON INSURANCE NUMBER:";
			cin>>pinsurance;
			cout<<"\n ENTER THE PERSON TELEPHONE NUMBER:";
			cin>>ptel;
			cout<<"\n ENTER THE PERSON LICENSE NUMBER:";
			cin>>plicense;
			cout<<"\n ENTER THE PERSON HEIGHT:";
			cin>>pheight;
			cout<<"\n ENTER THE PERSON WEIGHT:";
			cin>>pweight;
			p[cnt]=new person(pname,pblood,dd,paddress,pinsurance,ptel,plicense,pheight,pweight);
			a[cnt]=new age();
			cnt=cnt+1;
			break;

		case 3:				//NUMBER OF ENTRIES INFORMATION
			person::displaycount();
			break;
		case 4:				//CALCULATE AGE INFORMATION
			for(int i=0;i<cnt;i++)
			{
				p[i]->display();
				a[i]->calculate(p[i]);
			}
			break;
			
		case 5:				//TALLER PERSON INFORMATION
			temp = p[0];
			for(int j=1;j<cnt;j++)
			{
				temp = &temp->compare(p[j]);
			}
			cout<<"\n ------TALLER PERSON INFORMATON-------"<<endl;
			temp->display();
			break;
		case 6: 
		        return 0;		
	}
        }while(ch!=6);
}

/*--------------------output----------------------
 ---------------------------MENU--------------------------

 1.DEFAULT CONSTRUCTER 
 2.PARAMETERIZED CONSTRUCTOR
 3.NUMBER OF ENTRIES
 4.CALCULATE AGE:
 5.TALLER PERSON:
 6.EXIT
 ENTER THE CHOICE:1
-----------------default information------------
 PERSON NAME:default name
 BLOOD GROUP:O+
 DATE OF BIRTH:1996
 CONTACT ADDRESS:nasik
 INSURANCE NUMBER:12345
 TELEPHONE NUMBER:360410550
 LICENSE NUMBER:123456
 HEIGHT:10.2
 WEIGHT:120

 ---------------------------MENU--------------------------

 1.DEFAULT CONSTRUCTER 
 2.PARAMETERIZED CONSTRUCTOR
 3.NUMBER OF ENTRIES
 4.CALCULATE AGE:
 5.TALLER PERSON:
 6.EXIT
 ENTER THE CHOICE:2

 ENTER THE PERSON NAME:abc

 ENTER THE PERSON BLOOD GROUP:b+

 ENTER DATE OF BIRTH:1990

 ENTER THE PERSON CONTACT ADDRESS:nasik

 ENTER THE PERSON INSURANCE NUMBER:123

 ENTER THE PERSON TELEPHONE NUMBER:1234567890

 ENTER THE PERSON LICENSE NUMBER:345

 ENTER THE PERSON HEIGHT:4 

 ENTER THE PERSON WEIGHT:34

 ---------------------------MENU--------------------------

 1.DEFAULT CONSTRUCTER 
 2.PARAMETERIZED CONSTRUCTOR
 3.NUMBER OF ENTRIES
 4.CALCULATE AGE:
 5.TALLER PERSON:
 6.EXIT
 ENTER THE CHOICE:3

 NUMBER OF ENTRIS ARE:2

 ---------------------------MENU--------------------------

 1.DEFAULT CONSTRUCTER 
 2.PARAMETERIZED CONSTRUCTOR
 3.NUMBER OF ENTRIES
 4.CALCULATE AGE:
 5.TALLER PERSON:
 6.EXIT
 ENTER THE CHOICE:4

 PERSON NAME:default name
 BLOOD GROUP:O+
 DATE OF BIRTH:1996
 CONTACT ADDRESS:nasik
 INSURANCE NUMBER:12345
 TELEPHONE NUMBER:360410550
 LICENSE NUMBER:123456
 HEIGHT:10.2
 WEIGHT:120
 AGE:19

 PERSON NAME:abc
 BLOOD GROUP:b+
 DATE OF BIRTH:1990
 CONTACT ADDRESS:nasik
 INSURANCE NUMBER:123
 TELEPHONE NUMBER:1234567890
 LICENSE NUMBER:345
 HEIGHT:4
 WEIGHT:34
 AGE:25

 ---------------------------MENU--------------------------

 1.DEFAULT CONSTRUCTER 
 2.PARAMETERIZED CONSTRUCTOR
 3.NUMBER OF ENTRIES
 4.CALCULATE AGE:
 5.TALLER PERSON:
 6.EXIT
 ENTER THE CHOICE:5

 ------TALLER PERSON INFORMATON-------

 PERSON NAME:default name
 BLOOD GROUP:O+
 DATE OF BIRTH:1996
 CONTACT ADDRESS:nasik
 INSURANCE NUMBER:12345
 TELEPHONE NUMBER:360410550
 LICENSE NUMBER:123456
 HEIGHT:10.2
 WEIGHT:120

 ---------------------------MENU--------------------------

 1.DEFAULT CONSTRUCTER 
 2.PARAMETERIZED CONSTRUCTOR
 3.NUMBER OF ENTRIES
 4.CALCULATE AGE:
 5.TALLER PERSON:
 6.EXIT
 ENTER THE CHOICE:6
gescoe@gescoe-OptiPlex-3010:~/Desktop$ */
