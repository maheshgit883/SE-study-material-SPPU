#include<iostream>
#include<fstream>
#include<iomanip>
     
using namespace std;

class telephone
{
   	char name[20];
	char address[20];
    long int ph_no;
    public:
	telephone(){}
    	void get(void);
    	void show(void);
    	int getph_no();
};  
    
void telephone::get(void)
{
    	cout << "\nEnter Name: ";
    	cin>>name;
    	cout << "Enter Address: ";
    	cin>>address;
    	cout << "Enter Phone Number: ";
    	cin >> ph_no;
}
     
     
void telephone::show()
{
    	cout << "\nName: " << name;
    	cout << "\nAddress: " << address;
    	cout << "\nPhone Number: " << ph_no;
}
     
int  telephone::getph_no()
{
 	return ph_no;
}
     
     
void write_telephone()
{
    	telephone tel;
    	ofstream outFile;
    	outFile.open("D:/Second year study material/Object oriented programming/New folder (2)/Telephone_dir.txt", ios::binary | ios::app);
    	tel.get();
    	outFile.write(reinterpret_cast<char *> (&tel), sizeof(telephone));
    	outFile.close();
    	cout << "\n\nTelephone Directory Has Been Created...";
    	cin.ignore();
    	cin.get();
}
     
     
     
void display_all()
    {
    	telephone tel;
    	ifstream inFile;
    	inFile.open("D:/Second year study material/Object oriented programming/New folder (2)/Telephone_dir.txt", ios::binary);
    	if (!inFile)
    	{
    		cout << "File could not be open !! Press any Key...";
    		cin.ignore();
    		cin.get();
    		return;
    	}
    	cout << "\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
    	while (inFile.read(reinterpret_cast<char *> (&tel), sizeof(telephone)))
    	{
    		tel.show();
    		cout << "\n\n====================================\n";
    	}
    	inFile.close();
    	cin.ignore();
    	cin.get();
}
     
     
     
void searchph(int n)
{
    	telephone tel;
    	ifstream inFile;
    	inFile.open("D:/Second year study material/Object oriented programming/New folder (2)/Telephone_dir.txt", ios::binary);
    	if (!inFile)
    	{
    		cout << "File could not be open !! Press any Key...";
    		cin.ignore();
    		cin.get();
    		return;
    	}
    	bool flag = false;
    	while (inFile.read(reinterpret_cast<char *> (&tel), sizeof(telephone)))
    	{
    		if (tel.getph_no() == n)
    		{
    			tel.show();
    			flag = true;
    		}
    	}
    	inFile.close();
    	if (flag == false)
    		cout << "\n\nrecord not exist";
    	cin.ignore();
    	cin.get();
}
     
     
void modify_telephone(int n)
{
    	bool found = false;
    	telephone tel;
    	fstream File;
    	File.open("D:/Second year study material/Object oriented programming/New folder (2)/Telephone_dir.txt", ios::binary | ios::in | ios::out);
    	if (!File)
    	{
    		cout << "File could not be open !! Press any Key...";
    		cin.ignore();
    		cin.get();
    		return;
    	}
    	while (!File.eof() && found == false)
    	{
     
    		File.read(reinterpret_cast<char *> (&tel), sizeof(telephone));
    		if (tel.getph_no() == n)
    		{
    			tel.show();
    			cout << "\n\nPlease Enter The New Details" << endl;
    			tel.get();
    			int pos = (-1)*static_cast<int>(sizeof(tel));
    			File.seekp(pos, ios::cur);
    			File.write(reinterpret_cast<char *> (&tel), sizeof(telephone));
    			cout << "\n\n\t Record Updated";
    			found = true;
    		}
    	}
    	File.close();
    	if (found == false)
    		cout << "\n\n Record Not Found ";
    	cin.ignore();
    	cin.get();
}
     
     
     
void delete_telephone(int n)
{
    	telephone tel;
    	ifstream inFile;
    	inFile.open("D:/Second year study material/Object oriented programming/New folder (2)/Telephone_dir.txt", ios::binary);
    	if (!inFile)
    	{
    		cout << "File could not be open !! Press any Key...";
    		cin.ignore();
    		cin.get();
    		return;
    	}
    	ofstream outFile;
    	outFile.open("D:/Second year study material/Object oriented programming/New folder (2)/Temp.txt", ios::out);
    	inFile.seekg(0, ios::beg);
    	while (inFile.read(reinterpret_cast<char *> (&tel), sizeof(telephone)))
    	{
    		if (tel.getph_no() != n)
    		{
    			outFile.write(reinterpret_cast<char *> (&tel), sizeof(telephone));
    		}
    	}
    	outFile.close();
    	inFile.close();
    	remove("D:/Second year study material/Object oriented programming/New folder (2)/Telephone_dir.txt");
    	rename("D:/Second year study material/Object oriented programming/New folder (2)/Temp.txt", "D:/Second year study material/Object oriented programming/New folder (2)/Telephone_dir.txt");
    	cout << "\n\n\tRecord Deleted ..";
    	cin.ignore();
    	cin.get();
}
     
     
     
int main()
{
    	char ch;
    	int num;
    	cout.setf(ios::fixed | ios::showpoint);
    	cout << setprecision(2);
    	do
    	{
    		//system("cls");     
    		cout << "\n============================================";
    		cout << "\n\t1. Add Telephone Record";
    		cout << "\n\t2. Show Records";
    		cout << "\n\t3. Search Telephone Records";
    		cout << "\n\t4. Modify Record";
    		cout << "\n\t5. Delete Record";
    		cout << "\n\t6. EXIT";
    		cout << "\n============================================";
    		cout << "\n\tEnter Your Choice: ";
    		cin >> ch;
    		//system("cls");
    		switch (ch)
    		{
    		case '1':	write_telephone(); break;
    		case '2':	display_all(); break;
    		case '3':	cout << "\n\tPlease Enter Phone Number: "; cin >> num;
    			searchph(num); break;
    		case '4':	cout << "\n\tPlease Enter Phone Number: "; cin >> num;
    			modify_telephone(num); break;
    		case '5':	cout << "\n\tPlease Enter Phone Number: "; cin >> num;
    			delete_telephone(num); break;
    		case '6':	exit(0);
    		default:	cout << "\a";
     
    		}
    	}while (ch != '7');
     	try{
	     {throw 10;}}
	catch(int){
	     cout<<"Encountered Error !!";}
    	return 0;
}
