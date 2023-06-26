//Program to understand default constructor
#include <iostream>
using namespace std;
class Person{
//member variable declared as private
private:
   string name;
   int age;
   double height;
   public:
   Person(){      //default constructor
      name = "Santosh";
      age = 45;
      height = 6.55;
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
    //here you can initialize every object with same value
    
    Person per, per1, per2;

    per.showData();
    per1.showData();
    per2.showData();
    return 0;
}

