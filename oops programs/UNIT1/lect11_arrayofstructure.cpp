//Program to understand Array of Structures
#include <iostream>
#include <iomanip>
using namespace std;

struct Employee{  //structure definition
    int empId;
    string name;  
    double salary;
};

//function to accept input
void getEmpData(Employee emp[],int n){
    cout<<"Enter Employee Details(empid,name,salary):"<<endl;
    for(int i=0;i<n;i++){
        cin>>emp[i].empId>>emp[i].name>>emp[i].salary;
    }
}

//function to display output, uses manipulator to format output
void printEmpData(Employee emp[],int n){
    cout<<setw(12)<<"Emp Id"<<setw(20)<<"Employee Name"<<setw(12)<<"Salary"<<endl;
    for(int i=0;i<n;i++){
        cout<<setw(12)<<emp[i].empId<<setw(20)<<emp[i].name<<setw(12)<<emp[i].salary<<endl;
    }
}
//main function
int main()
{
    int ne;
    cout<<"Enter no. of employees:"<<endl;
    cin>>ne;
    Employee empp[ne];
    getEmpData(empp,ne);
    cout<<"***********Employee Details***********"<<endl;
    printEmpData(empp,ne);
    return 0;
}

