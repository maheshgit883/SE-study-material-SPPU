//MAHESH JAGTAP ROLLNO.21027
//Write a C++ program that creates an output file, writes information to it, closes the file
//and open it again as an input file and read the information from the file.
#include <iostream>
#include <fstream>
using namespace std;
 
class student
{
private:
    string name;
    int roll;
public:
    void accept();
    void display();

};
 
 
void student::accept()
{cout<<"\n\tEnter name: ";
 cin>>name;
 cout<<"\tEnter Roll no: ";
 cin>>roll;
}
void student::display()
{cout<<"\n\tName: "<<name;
 cout<<"\tRoll no: "<<roll;
}

int main()
{
    int n,i;
    cout<<"\nEnter number of students :";
    cin>>n;
    student s[n];       //array of object
    fstream fs;          // Creating object of fstream class
    fs.open("D:\\Second year study material\\Object oriented programming\\oops programs\\final programs\\file.txt",ios::app);   //Opening file in append mode
    cout<<"(Writing student information into the file....)";
    cout<<"\n\tEnter student details :";
    for (i = 0; i <n; i++)
    {
    s[i].accept();
    fs.write((char *)&s[i],sizeof(s[i]));
    }
    cout<<"\n(closing the file...)";
    fs.close();
    fs.open("D:\\Second year study material\\Object oriented programming\\oops programs\\final programs\\file.txt",ios::in);
    cout<<"\n(opening the file again..)";
    cout<<"\n(Reading students information from the file..)"<<endl;
    for (i = 0; i <n; i++)
    {
    fs.read((char *)&s[i],sizeof(s[i]));
    s[i].display();
    }
    cout<<"\n\n(Closing the file...)";
    fs.close();
    return 0;
}