//Program to understand Structure in Structure/Nested Structures
#include <iostream>
using namespace std;
struct EmpName{  //structure definition for name
    string fname;
    string mname;
    string lname;
};
struct EmpDob{   //structure definition for date of birth
    int dd, mm, yy;
};
struct Employee{  //main structure which contains above both structure
    int empId;
    EmpName eName;  
    EmpDob eDob;
};
int main(){
    Employee emp;
    cout<<"Enter Employee Details(empid, empname, dob)"<<endl;
    //take the input
    cin>>emp.empId;
    cin>>emp.eName.fname>>emp.eName.mname>>emp.eName.lname;
    cin>>emp.eDob.dd>>emp.eDob.mm>>emp.eDob.yy;
    //display the output
    cout<<"Employee Details:"<<endl;
    cout<<"Emp ID:"<<emp.empId<<endl;
    cout<<"Emp Name: "<<emp.eName.fname<<" "<<emp.eName.mname<<" "<<emp.eName.lname<<endl;
    cout<<"Emp DoB: "<<emp.eDob.dd<<"/"<<emp.eDob.mm<<"/"<<emp.eDob.yy;
    return 0;
}
