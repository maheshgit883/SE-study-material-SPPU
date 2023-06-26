//Program to pass structure variable as a parameter to a function
#include <iostream>
using namespace std;
struct Person{   //structure definition
    string name;
    int age;
    float height;
};
//function to take input
void getPersonData(Person& p){   //function has structure variable as a parameter with reference
    cout<<"Enter Person Details:";
    cin>>p.name>>p.age>>p.height;
}
//function to display output
void showPersonData(Person p){   //function has structure variable as a parameter
    cout<<"Person Details"<<endl;
    cout<<"Name: "<<p.name<<endl;
    cout<<"Age: "<<p.age<<endl;
    cout<<"Height: "<<p.height<<endl;
}
//main function
int main()
{
    Person per;
    getPersonData(per);
    showPersonData(per);
    return 0;
}

