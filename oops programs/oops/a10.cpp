=======================================================================
Assignment No.: A10
Title	      : Write a function in C++ to count and display the number of lines not starting 			with alphabet 'A' present in a text file "STORY.TXT".
		Example:
			If the file "STORY.TXT" contains the following lines,
			1 The rose is red.
			2 A girl is playing there.
			3 There is a playground.
			4 An aeroplane is in the sky.
			5 Numbers are not allowed in the password.
CLASS	      :	SE(B)
Batch	      : SB(5)
ROLL NO	      :	95
Date	      :  
========================================================================

#include<iostream> //ANSI standard header file
#include<fstream> // header file for handle stream in file
using namespace std; //declared scope of the program
int main() //main function
{
	ifstream fin; //fin object created
	fin.open("STORY.txt"); //open method
	char str[80]; //lenth of string
	int count=0; //count initialized by zero
	while(!fin.eof())
	{
		fin.getline(str,80);
		if(str[0]!='A') //first position of line is not equal to 'A'
			count++;
	}
	cout<<"Number of lines not starting with A are: " <<"\t" <<count <<"\n";
	fin.close(); //close method to close the file
	return 0;
}

-------------------------------------------OUTPUT-----------------------------------------------
srl@srl-Lenovo-G550:~/Desktop/OOP$ g++ a10.cpp
srl@srl-Lenovo-G550:~/Desktop/OOP$ ./a.out
Number of lines not starting with A are: 4

 
