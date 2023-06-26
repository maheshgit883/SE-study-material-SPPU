/*B-15
Write a menu driven program that will create a data file containing the list of telephone
numbers in the following form
John 23456
Ahmed 9876
........... .........
Use a class object to store each set of data, access the file created and implement the following tasks
I.Determine the telephone number of specified person
II.Determine the name if telephone number is known
III.Update the telephone number, whenever there is a change.

BATCH:y
ROLL NO.:
DATE:
*/ 
#include <iostream> //standard input output stream header file
#include <fstream> //handled input output file stream for read and write purpose

#include <string.h> //for sring operation purpose eg. strcpy()
#include <iomanip> //for manupulation purpose eg. seekg(), seekp(), setw()

using namespace std;

class phoneBook{			//phoneBook class
    char name[20],phno[15];		//veriable declaration
    public:
    void getdata();			//function declaration
    void showdata();
    char *getname(){ return name; }
    char *getphno(){ return phno; }
    void update(char *nm,char *telno){
        strcpy(name,nm);		//string copy method is used
        strcpy(phno,telno);
    }
};

void phoneBook :: getdata(){
    cout<<"\nEnter Name : ";
    cin>>name;
    cout<<"Enter Phone No. : ";
    cin>>phno;
}

void phoneBook :: showdata(){
    cout<<"\n";
    cout<<setw(20)<<name;
    cout<<setw(15)<<phno;
}


int main(){		// main function declaration
    phoneBook rec;	// rec object is created
    fstream file;	//file obj is created of fstream
file.open("//home//gescoe//Desktop//OOPL//phone.txt", ios::ate | ios::in | ios::out | ios::binary); 
			//ate= read/write at the end of file, input, output, binary file.
    char ch,nm[20],telno[6];
    int choice=0,found=0;
    while(choice<6){       
 	
        cout<<"\n*****Phone Book*****\n";
        cout<<"1) Add New Record\n";
        cout<<"2) Display All Records\n";
        cout<<"3) Search Telephone No.\n";
        cout<<"4) Search Person Name\n";
        cout<<"5) Update Telephone No.\n";
        cout<<"6) Exit\n";
        cout<<"Choose your choice : ";
        cin>>choice;
        switch(choice){
            case 1 : //New Record
                 rec.getdata();
                 cin.get(ch);
                 file.write((char *) &rec, sizeof(rec));
                 break;

            case 2 : //Display All Records
                 file.seekg(0,ios::beg);//seekg is used to move the position to the end of the file
                 cout<<"\n\nRecords in Phone Book\n";	
                 while(file){
                    file.read((char *) &rec, sizeof(rec));
                    if(!file.eof())
                        rec.showdata();
                 }
                 file.clear();
                 break;

            case 3 : //Search Tel. no. when person name is known.
                 cout<<"\n\nEnter Name : ";
                 cin>>nm;
                 file.seekg(0,ios::beg);
                 found=0;
                 while(file.read((char *) &rec, sizeof(rec)))
                 {
                    if(strcmp(nm,rec.getname())==0)
                    {
                        found=1;
                        rec.showdata();
                    }
                 }
                 file.clear();
                 if(found==0)
                    cout<<"\n\n---Record Not found---\n";
                 
                 break;

            case 4 : //Search name on basis phone no.
                 cout<<"\n\nEnter Telephone No : ";
                 cin>>telno;
                 file.seekg(0,ios::beg);
                 found=0;
                 while(file.read((char *) &rec, sizeof(rec)))
                 {
                    if(strcmp(telno,rec.getphno())==0)
                    {
                        found=1;
                        rec.showdata();
                    }
                 }
                 file.clear();
                 if(found==0)
                    cout<<"\n\n---Record Not found---\n";
                
                 break;

            case 5 : //Update Telephone No.
                 cout<<"\n\nEnter Name : ";
                 cin>>nm;
                 file.seekg(0,ios::beg);
                 found=0;
                 int cnt=0;
                 while(file.read((char *) &rec, sizeof(rec)))
                 {
                    cnt++;
                    if(strcmp(nm,rec.getname())==0)
                    {
                        found=1;
                        break;
                    }
                 }
                 file.clear();
                 if(found==0)
                    cout<<"\n\n---Record Not found---\n";
                 else
                 {
                    int location = (cnt-1) * sizeof(rec);
                    cin.get(ch);
                    if(file.eof())
                        file.clear();

                    cout<<"Enter New Telephone No : ";
                    cin>>telno;
                    file.seekp(location);	//seekp() and seekg() are to position the put and get pointers in some random position.
                    rec.update(nm,telno);
                    file.write((char *) &rec, sizeof(rec));
                    file.flush();
                 }
                 break;
            
        }
}
return 0;
    }
 
