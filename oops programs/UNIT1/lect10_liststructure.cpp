//Program to understand use of arrays in structures
#include <iostream>
using namespace std;
const int SIZE = 100;  //constant to define size of array
struct listType{   //List defined using structure
    int listElem[SIZE];    //list array
    int length;    //length of list
};
//take input of list elements and its length
void getListElements(listType& lt){
    cout<<"how many elements do you want in the list";
    cin>>lt.length;
    for(int i=0;i<lt.length;i++){
        cin>>lt.listElem[i];
    }
}

//display list
void printListElements(listType lt){
    for(int i=0;i<lt.length;i++){
        cout<<lt.listElem[i]<<" ";
    }
}

//perform sequential search on the list
int seqSearch(const listType& lt, int searchItem){
    int loc;
    bool found = false;
    for(loc=0;loc<lt.length;loc++){
        if(lt.listElem[loc]==searchItem){
            found = true;
            break;
        }
    }
    if(found){
        return loc;
    }
    else{
        return -1;
    }
}
//main function
int main(){
    listType listt;
    int n;
    int f;
    getListElements(listt);
    cout<<"List Elements are:"<<endl;
    printListElements(listt);
    cout<<"\nEnter the number to be searched:"<<endl;
    cin>>n;
    f = seqSearch(listt,n);
    if(f==-1){
        cout<<"\nElement does not exist in the list"<<endl;
    }
    else{
        cout<<"\nElement found at location: "<<f<<endl;
    }
    return 0;
}
