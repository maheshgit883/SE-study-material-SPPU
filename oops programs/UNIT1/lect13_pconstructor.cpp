//Program to understand parameterized constructor
#include <iostream>
using namespace std;
class Person{
//member variable declared as private
private:
   string name;
   int age;
   double height;
   public:
   Person(string n, int a, double h){  //paramterised constructor
      name = n;
      age = a;
      height = h;
   }

   /*member function to display output*/
   void showData(){
   cout<<"Name: "<<name<<endl;
   cout<<"Age: "<<age<<endl;
   cout<<"Height: "<<height<<endl;
   }
};
int main()
{   //object creation and constructor invocation
    //here you can initialize every object with different value
    Person per("Santosh", 56, 9.56);
    Person per1("Suresh", 34, 8.45);
    Person per2("Satish", 23, 3.55);

    per.showData();
    per1.showData();
    per2.showData();
    return 0;
}

