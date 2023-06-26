// Develop a program in C++ to create a database of student’s information system containing the following information: Name, Roll number, Class, Division, Date of Birth, Blood group, Contact address, Telephone number, Driving license no. and other. Construct the database with suitable member functions. Make use of constructor, default constructor, copy constructor, destructor, static member functions, friend class, this pointer, inline code and dynamic memory allocation operators-new and delete as well as exception handling.

#include<iostream>
#include<string>
using namespace std;
class per_info
{ long int contact; 
  string address,license,blood;
  public:
    per_info();//DECLARATION OF DEFAULT COUNSTRUCTOR
    per_info(per_info &);//DECLARATION OF COPY COUNSTRUCTOR
    ~per_info()
    {
      cout<<"\n DESTRUCTOR IS CALLED !!!"<<endl<<"RECORDS DELETED SUCESSFULLY.."<<endl;
    }
    friend class student;// Declaration Friend class
};   
 per_info::per_info() //Default constructor definition
	{
	  contact=01234567;
		address="XYZ";
		license="XY-0000000000";
		blood="O+";
  }
  per_info::per_info(per_info &obj) ////copy constructor definition
  {
    contact=obj.contact;
    address=obj.address;
    license=obj.license;
    blood=obj.blood;
  }


      //Definition of friend  student class
class student
{  int roll_no;
	 string name,division,year,dob; 
   static int count;    //static variable

	public:
	
    void getdata(per_info &obj)
    {cout<<"\n Enter name :  ";
      cin>>name;
       cout<<"Enter date of birth : ";
     cin>>dob;
      cout<<"Enter roll no. : ";
      cin>>roll_no;
       cout<<"Enter year : ";
      cin>>year;
       cout<<"Enter division : ";
     cin>>division;
    cout<<"Enter blood group  :  ";
     cin>>obj.blood;
    cout<<"Enter address : ";
    cin>>obj.address;
    cout<<"Enter Licence number : ";
     cin>>obj.license;
    cout<<"Enter Contact number : ";
    cin>>obj.contact;}
    
 
    void showdata(per_info &obj)
    {
    cout<<"\n*********************************";
    cout<<"\n"<<"NAME : " <<name;
    cout<<"\n"<<"DATE OF BIRTH : "<<dob;
    cout<<"\n"<<"ROLL NO. : "<<roll_no;
    cout<<"\n"<<"CLASS : "<<year;
    cout<<"\n"<<"DIVISION : "<<division;
    cout<<"\n"<<"BLOOD GROUP : "<<obj.blood;
    cout<<"\n"<<"ADDRESS : "<<obj.address;
    cout<<"\n"<<"LICENSE : "<<obj.license;
    cout<<"\n"<<"CONTACT NO. : "<<obj.contact;
    }

    inline static void incrcount()
    {
      count++;
    }

    inline static void showcount()
    {
      cout<<"\n TOTAL NO. OF RECORDS ARE : "<<count;
    }

    student(); //DECLARATION OF DEFAULT COUNSTRUCTOR
    student(student &); //DECLARATION OF COPY COUNSTRUCTOR
    ~student()
    {
        cout<<"\n DESTRUCTOR IS CALLED !!!"<<endl<<"RECORDS DELETED SUCESSFULLY.."<<endl;
    }
};
 int student ::count;

student ::student() //Default constructor definition
{   name="ABC";
    dob="dd/mm/yy";
    roll_no=0;
    division="A";
    year="FE";
}
student ::student(student &obj) //COPY constructor definition
{
  this->name=obj.name;    //this pointer
  this->dob=obj.dob;
  this->roll_no=obj.roll_no;
  this->division=obj.division;
  this->year=obj.year;
}

int main()
{
  int n,choice;
  char ans;

  cout<<"ENTER NO. OF STUDENTS : ";
  cin>>n;
  student *sobj=new student[n];
  per_info *pobj=new per_info[n];
  do
  { cout<<"\n---------------------------";
    cout<<"\n MENU : \n 1.CREATE DATABASE \n 2.DISPLAY DATABASE \n 3.DEFAULT CONSTRUCTOR  \n 4.COPY CONSTRUCTOR \n 5. DELETE(Destructor) ";
    cout<<"\n\nENTER YOUR CHOICE : ";
    cin>>choice;
    switch (choice)
    {
    case 1:   //create database
      { cout<<"\n*****creating database******";
        for (int i=0;i<n;i++)
        {
            sobj[i].getdata(pobj[i]);
            sobj[i].incrcount();
      }
      break;
      }
    case 2:   //display database
    { cout<<"******displaying database******";
      sobj[0].showcount();
     for (int i=0;i<n;i++)
      {
         sobj[i].showdata(pobj[i]);
         
      }
    }
      break;
    case 3:   //default constructor
    {
      student s1;
      per_info p1;
      cout<<"\n DEFAULT CONSTRUCTOR IS CALLED ";
      s1.showdata(p1);
    }
      break;
    case 4:   //copy constructor
      {
        student s1;
        per_info p1;
        s1.getdata(p1);
        student s2(s1);
        per_info p2(p1);
        cout<<"\n COPY CONSTRUCTOR IS CALLED ";
        s2.showdata(p2);
      }
      break;
    case 5:   //destructor  
    {
       delete [] sobj;  //A destructor is  executed when delete expression is applied to a pointer to the object of that class.
       delete [] pobj;
    }
    }
    cout<<"\n *DO YOU WANT TO CONTINUE (Y/N):  " ;
    cin>>ans;    
  } while (ans=='Y' || ans=='y');
  
return 0;
}

