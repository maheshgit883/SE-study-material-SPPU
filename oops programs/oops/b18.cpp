/* B-18 Write a function template selection Sort. Write a program that inputs, sorts and outputs an integer array and a float array.*/

#include<iostream> //header file

using namespace std; //declared the scope of our program

template<typename T> //template definition
void sort(T a[],int n) //sorting function
{
int pos_min, temp, i; //variable declaration
	for(int i=0;i<n-1;i++)
	{
	pos_min=i;
	for(int j=i+1;j<n;j++)
	{
	if(a[j]<a[pos_min])
	pos_min=j;
	}
	if(pos_min!=i)
		{
		temp=a[i];
		a[i]=a[pos_min];
		a[pos_min]=temp;
		}
	}

//display sorted elements
cout<<"\n Sorted elements are:\n";
for(i=0;i<n;i++)
cout<<"\t"<<a[i];
}

int main()
{
int n, i;
int a[10];
float b[10];

cout<<"\n Selection  sort using function template";

cout<<"\n Sorting int numbers";
cout<<"\n Enter how many number wanted to sort:";
cin>>n;
	for(i=0;i<n;i++)
	cin>>a[i];
	sort<int>(a, n);

cout<<"\n Sorting floating point numbers";
cout<<"\n Enter how many number wanted to sort:";
cin>>b[i];
	for(i=0;i<n;i++)
	cin>>b[i];
	sort<float>(b, n);
return 0;
}

/*OUTPUT
srl@srl-Lenovo-G550:~/Desktop/OOPL$ g++ b18.cpp
srl@srl-Lenovo-G550:~/Desktop/OOPL$ ./a.out

 Selection  sort using function template
 Sorting int numbers
 Enter how many number wanted to sort:5
5
4
3
2
1

 Sorted elements are:
	1	2	3	4	5
 Sorting floating point numbers
 Enter how many number wanted to sort:5
5
4
3.3
2.2
1.1

 Sorted elements are:
	1.1	2.2	3.3	4	5
*/
