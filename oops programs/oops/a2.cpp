/*Assignment No: A-2
Title:  Design a C++ Class ‘Complex ‘ with data members for real and imaginary part. Provide
        default and parameterized constructors. Write a program to perform arithmetic operations
        of two complex numbers using operator overloading (using either member functions or
        friend functions).
Roll No: 
Batch: 
Date:
*/

#include<iostream> //header file
#include<stdlib.h>
#include <iomanip> 

using namespace std; //declared the scope of program

class complex //class name complex
{

float real,img; //declared variable of type float
 
  public:
        complex()             		  //default constructor
        {
        }
        complex(float a,float b)       	 //parameterized constructor
        {
                real=a;
                img=b;
        }
        void accept()
        {
                cout<<"\nEnter Real Number:";
                cin>>real;
                cout<<"\nEnter Imaginary Number:";
                cin>>img;
        }
        void display()
        {
                cout<<"\nReal Number:\n"<<real;
                cout<<"\nImaginary Number:\n"<<img<<"i\n";
        }
        friend complex operator + (complex ,complex);           //Friend Functions
        friend complex operator - (complex ,complex);
        complex operator * (complex);
        complex operator / (complex);
};
complex operator + (complex x,complex y) 
{
        complex temp;
        temp.real=x.real+y.real;
        temp.img=x.img+y.img;
        return (temp);
}
complex operator - (complex x,complex y)
{
        complex temp;
        temp.real=x.real - y.real;
        temp.img=x.img - y.img;
        return (temp);
}
complex complex:: operator * (complex x) 
{
        complex temp;
        temp.real=real*x.real-(img*x.img);
        temp.img=real*x.img+(img*x.real);
        return (temp);
}
complex complex:: operator / (complex x) 
{
        complex temp;
        temp.real=((real*x.real)+(img*x.img))/((x.real*x.real)+(x.img*x.img));
        temp.img=((img*x.real)-(real*x.img))/((x.real*x.real)+(x.img*x.img));
        return (temp);
}
int main() //main function
{ 
        int ch; //variable declaration main fun
        complex c1,c2,c3,c4,c5,c6;//variable declaration of main fun
        do 
	{
		cout<<"\n********* MENU *********";
		cout<<"\n1. Addition";
		cout<<"\n2. Substraction";
		cout<<"\n3. Multiplication";
		cout<<"\n4. Division";
		cout<<"\n5. Exit";
		cout<<"\nEnter The choice:";
		cin>>ch;
		switch(ch)
		{
			case 1: 
			        cout<<"\nEnter First Complex Number";
			        c1.accept();
			        cout<<"Enter Second Complex Number\n";
			        c2.accept();
			        c3=c1 + c2;
			        cout<<"\nAddition Of Numbers:";
			        c3.display();
                        break;
                        case 2:
                                cout<<"\nEnter First Complex Number";
                                c1.accept();
                                cout<<"Enter Second Complex Number\n";
                                c2.accept();
                                c4=operator - (c1,c2);
                                cout<<"\nSubstaction Of Numbers:";
                                c4.display();
                        break;
                        case 3:
                                cout<<"\nEnter First Complex Number";
                                c1.accept();
                                cout<<"Enter Second Complex Number\n";
                                c2.accept();
                                c5=c1 * c2;
                                cout<<"\nMultiplication Of Numbers:";
                                c5.display();
                        break;
                        case 4:
                                 cout<<"\nEnter First Complex Number";
                                c1.accept();
                                cout<<"Enter Second Complex Number\n";
                                c2.accept();
                                c6=c1 / c2;
                                cout<<"\nDivision Of Numbers:";
                                c6.display();
                        break;
                        case 5:
                                return 0;
                        break;
                 }
        }while(ch!=5);     
}
/*OUTPUT:
gescoe@gescoe-OptiPlex-3010:~/Desktop/SE-41$ g++ prac4.cpp
gescoe@gescoe-OptiPlex-3010:~/Desktop/SE-41$ ./a.out

********* MENU *********
1. Addition
2. Substraction
3. Multiplication
4. Division
5. Exit
Enter The choice:1

Enter First Complex Number
Enter Real Number:2

Enter Imaginary Number:3
Enter Second Complex Number

Enter Real Number:4

Enter Imaginary Number:5

Addition Of Numbers:
Real Number:
6
Imaginary Number:
8i
********* MENU *********
1. Addition
2. Substraction
3. Multiplication
4. Division
5. Exit
Enter The choice:2

Enter First Complex Number
Enter Real Number:5

Enter Imaginary Number:6
Enter Second Complex Number

Enter Real Number:2

Enter Imaginary Number:3

Substaction Of Numbers:
Real Number:
3
Imaginary Number:
3i
********* MENU *********
1. Addition
2. Substraction
3. Multiplication
4. Division
5. Exit
Enter The choice:3

Enter First Complex Number
Enter Real Number:2

Enter Imaginary Number:5
Enter Second Complex Number

Enter Real Number:3

Enter Imaginary Number:2

Multiplication Of Numbers:
Real Number:
-4
Imaginary Number:
19
********* MENU *********
1. Addition
2. Substraction
3. Multiplication
4. Division
5. Exit
Enter The choice:4

Enter First Complex Number
Enter Real Number:8

Enter Imaginary Number:9
Enter Second Complex Number

Enter Real Number:2

Enter Imaginary Number:3

Division Of Numbers:
Real Number:
3.30769
Imaginary Number:
-0.461538
********* MENU *********
1. Addition
2. Substraction
3. Multiplication
4. Division
5. Exit
Enter The choice:5
*/


