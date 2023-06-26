//MAHESH JAGTAP ROLL NO.21027  SE A 
/*PROBLEM STATEMENT  :Imagine a publishing company which does marketing for book and audio cassette versions. Create a class
publication that stores the title (a string) and price (type float) of publications. From this class derive 
two classes: book which adds a page count (type int) and tape which adds a playing time in minutes (type float).
Write a program that instantiates the book and tape class, allows user to enter data and displays the data members. 
 If an exception is caught, replace all the data member values with zero values*/


#include<iostream>
using namespace std;
class publication          //Base Class
{
protected:
    string title;
    float price;
public:
    publication()                 //Default Constructor
    {
        title="Hello";
        price=0;
    }
    publication(string t,float p)   //Parameterized Constructor
    {
        t=title;
        p=price;
    }
    void getdata()
    {
        cout<<"Enter the title :";
        cin.ignore();
        getline(cin, title);
        cout<<"Enter the price(rs.):";
        cin>>price;
    }
    void displaydata()
    {
        cout<<"Title is:"<<title<<endl ;
        cout<<"Price is:"<<price<<"rs"<<endl;
    }
    ~publication(){};

};
class Book:public publication     //Derived Class
{
     int pagecount;
public:
    Book()               //Default Constructor
    {
        pagecount=0;
    }
    Book(string t , float p , int pgcnt) :publication(t,p) //ParameterizedConstructor and constructor of base class is being called
    {
        pgcnt=pagecount;
    }
    
    void getdata01()  //Input book data
    {
        try
        {
            getdata();
            cout<<"Enter page count:";
            cin>>pagecount;
            if(pagecount<=0)
            {
                throw pagecount;
                
            }
        } catch (...)
        {
            cout<<"invalid page count";
            pagecount=0;
        }
    }
       
    void display01()    //Displaybookdata
    {
        displaydata();
        cout<<"No of Pages in book:"<<pagecount<<endl ;
    }
    ~Book(){};
};
class Tape :public publication  //Child Class TAPE from base class
{
    float Playingtime;
public:
    Tape()                       //Default constructor
    {
        Playingtime = 0;
    }
    Tape(string t, float p, float  playtym) : publication(t,p)  //ParameterizedConstructor and constructor of base class is being called
    {
        playtym=Playingtime;
    }
    
    void getdata02()             //Input audiocassete data
    {
        try {
            getdata();
            cout<<"Enter number of minutes of playing:" ;
                   cin>>Playingtime;
            if(Playingtime<=0)
            {
                throw Playingtime;
            }
        } catch (...)
        {
            cout<<"Invaid playing time";
            Playingtime=0;
        }
    }
    void display02()                          //Display cassete data
    {
        displaydata();
        cout<<"Playing time of Cassette:"<<Playingtime<<"min"<<endl;
    }
    ~Tape(){};
};
int main()
{
    int choice,b_count=0,t_count=0;
    Book b1[10];
    Tape t1[10];
    do
    {
        cout<<"**************Publication Info************"<<endl;
        cout<<"---------Menu---------"<<endl;
        cout<<"1.Add information to book"<<endl;
        cout<<"2.Add information to Tape"<<endl;
        cout<<"3.Display Books information"<<endl;
        cout<<"4.Display Tapes information"<<endl;
        cout<<"5.Exit"<<endl;
        cout<<"Enter choice:";
        cin>>choice;
        switch (choice)
        {
                case 1:
                b1[b_count].getdata01();
                b_count++;
                break;
            case 2:
                t1[t_count].getdata02();
                t_count++;
                break;
            case 3:
                cout<<"*********************Publication info(Books)*********************";
                cout<<"\n";  cout<<"\n";  cout<<"\n";
                for(int i = 0 ; i<b_count;i++)
                {
                    b1[i].display01();
                }
                       cout<<"\n";  cout<<"\n";  cout<<"\n";
                break;
                case 4:
                       cout<<" *********************Publication info(Tapes)*********************";
                               cout<<"\n";  cout<<"\n";  cout<<"\n";
                              for(int i = 0 ; i<t_count;i++)
                              {
                                  t1[i].display02();
                              }       cout<<"\n";  cout<<"\n";  cout<<"\n";
                              break;
            case 5:
                 cout<<"--------------------------------ThankYou!!------------------------------------"<<endl;
        }
        } while (choice!=5);
    return 0;
}