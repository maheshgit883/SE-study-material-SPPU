#include <iostream>
using namespace std;
class Person{
//member variable declared as private
private:
   string name;
   int age;
   double height;
   
public:  
/*member function to get input*/
   void getData(){
   cout<<"Enter Person Details:"<<endl;
   cin>>name>>age>>height;
   }
   
/*member function to display output*/
   void showData(){
   cout<<"Name: "<<name<<endl;
   cout<<"Age: "<<age<<endl;
   cout<<"Height: "<<height<<endl;
   }
};
int main()
{
    Person per;
    per.getData();
    per.showData();
    return 0;
}

