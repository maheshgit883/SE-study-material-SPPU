//MAHESH JAGTAP ROLLNO.21027
//Write a C++ program that creates an output file, writes information to it, closes the file
//and open it again as an input file and read the information from the file.

#include <fstream>
#include<iostream>
#include<conio.h>
using namespace std;
class student
{
private:
    string name;
    int rollno;
public:
    void add_info()
    {
    fstream fs; // Creating object of fstream class
    fs.open("D:\\Second year study material\\Object oriented programming\\oops programs\\final programs\\file.txt", ios::app);//Opening file in append mode
    if (!fs)  // Checking whether file exist
        cout<<"File creation failed...";
    else
        {//cout<<" New file created. ..";
        cout << "\n Enter name :";
        cin >> name;
        cout << "Enter Rollno :";
        cin >> rollno;
        fs << name << " ";  //write name to file
        fs << rollno << "\n"; // write rollno to file
        fs.close ();
        }
    }//end of add info

    void display_info ()
    {
    fstream fs; //creating abject of fstream class
    fs.open("D:\\Second year study material\\Object oriented programming\\oops programs\\final programs\\file.txt", ios::in) ; //opening file in input mode
    if (!fs)    // Checking whether file exist
        cout<<"No such file....";
    else
    {while (! fs.eof())// read till end of the Eile
        {
            fs>>name; // Reading name from file
            fs>>rollno;   //Reading roll no from file
            if (!fs.eof())    //checking whether reached eof
            {cout << name << " ";
             cout << rollno;
             cout <<"\n";
            }// end of if
        }// end of while
    fs.close (); //closing file
    }
    }
};

int main ()
{
    int ch;
    student s;
    fstream fs;//creating object of fstream class
    do
    {
    cout<<"\n ***Student Information System***";
    cout<<" \n------Menu-----";
    cout<<" \n 1. Add Information ";
    cout<<" \n 2. Display Information ";
    cout<<" \n 3. Exit ";
    cout<<" \n Enter Choice:";
    cin>>ch;

    switch (ch)
    {   case 1:// add the info
            s.add_info () ;
            break;
        case 2:// Display info
            s.display_info ();
            break;
        case 3:
            exit (0);// successful exit of program
    }// end of switch statement
    }while(ch != 3) ;// end of while
return 0;
}
