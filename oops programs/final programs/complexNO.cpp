// Implement a class Complex which represents the Complex Number data type. Implement the following 
// 1. Constructor (including a default constructor which creates the complex number 0+0i). 
// 2. Overload operator+ to add two complex numbers.
// 3. Overload operator* to multiply two complex numbers. 
// 4. Overload operators << and >> to print and read Complex Numbers.

#include<iostream>
using namespace std;
class complex
{
public:
    float real,img;
    complex()           //constructor
    {
    real=0;
    img=0;
    }
    complex operator +(complex);
    complex operator *(complex);
    friend ostream &operator<<(ostream&,complex&);//we want to allow them to acess private data members of the class,so we will make  them friend function 
    friend istream &operator>>(istream&,complex&);
};
//this is automatically called when + is used between two complex objects
complex complex::operator +(complex obj)
{
    complex temp;
    temp.real=real+obj.real;
    temp.img=img+obj.img;
    return (temp);
}

//this is automatically called when * is used between two complex objects

complex complex::operator *(complex obj)
{
    complex temp;
    temp.real=(real*obj.real)-(img*obj.img);
    temp.img=(real*obj.img)+(img+obj.img);
    return (temp);
}

istream &operator>>(istream& is,complex& obj)
{
    is>>obj.real;
    is>>obj.img;
    return is;

}

ostream &operator<<(ostream& os,complex& obj)
{
    os<<obj.real;
    os<<"+"<<obj.img<<"i";
    return os;
}

int main()
{
    complex a,b,c,d;
    cout<<"\n Enter first complex number"<<endl;
    cout<<"\tEnter real and imaginary part of first complex number:";
    cin>>a;         //this will call the overloaded extraction function

    cout<<"\n Enter second complex number"<<endl;
    cout<<"\tEnter real and imaginary part of second complex number:";
    cin>>b;

    cout<<"\n Arithmetic operations are :";
    c=a+b;
    cout<<"\n Addition is:"<<c;  //this will call the overloaded insertion function

   
    d=a*b;
    cout<<"\n Multiplication is:"<<d<<"\n";
    return 0;
}
