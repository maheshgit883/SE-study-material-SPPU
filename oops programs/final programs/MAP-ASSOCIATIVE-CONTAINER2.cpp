// Write a program in C++ to use map associative container. The keys will be the names of states
// and the values will be the populations of the states. When the program runs, the user is
// prompted to type the name of a state. The program then looks in the map, using the state
// name as an index and returns the population of the state.


#include <iostream>
#include <map>  //To use a map, we must include the header file <map>
#include <string>
 #include <utility>

using namespace std;    //Include the std namespace into our code to use its classes without calling it.

int main()
{   //declaration of map
	typedef map<string,int> mapType;   //string is datatype of map keys
                    //int is the datatype of the values corresponding to the map keys.
                    //The mapType is the name of the map.
	mapType populationMap;
	

    //we are inserting a key/value pair in three different ways:
    //1.Use pair<>
    //2.Use value_type
    //3.Use make_pair
	populationMap.insert(pair<string, float>("Maharashtra", 125));
	populationMap.insert(pair<string, float>("Uttar Pradesh", 225));
	populationMap.insert(mapType::value_type("Bihar", 120)); 
	populationMap.insert(mapType::value_type("West Bengal", 100)); 
	populationMap.insert(make_pair("Madhya Pradesh", 90)); 
	populationMap.insert(make_pair("Tamil Nadu", 80)); 
	populationMap.insert(make_pair("Rajasthan", 78));
	populationMap.insert(make_pair("Andhra Pradesh", 53));
	populationMap.insert(make_pair("Odisha", 47));
	populationMap.insert(make_pair("Kerala", 38));
	populationMap.insert(make_pair("Telangana", 37));
	populationMap.insert(make_pair("Assam", 35));
	populationMap.insert(make_pair("Jharkhand", 38));
	populationMap.insert(make_pair("Karnataka", 68));
	populationMap.insert(make_pair("Gujarat", 70));
	populationMap.insert(make_pair("Punjab", 31));
	populationMap.insert(make_pair("Chhattisgarh", 30));
	populationMap.insert(make_pair("Haryana", 29));
	populationMap.insert(make_pair("Uttarakhand", 12));
	populationMap.insert(make_pair("Himachal Pradesh", 8));
	populationMap.insert(make_pair("Tripura", 04));
	populationMap.insert(make_pair("Meghalaya", 4));
	populationMap.insert(make_pair("Manipur[", 3));
	populationMap.insert(make_pair("Nagaland", 2));
	populationMap.insert(make_pair("Goa", 2));
	populationMap.insert(make_pair("Arunachal Pradesh", 2));
	populationMap.insert(make_pair("Mizoram", 1));
	populationMap.insert(make_pair("Sikkim", 1));
	
	mapType::iterator iter = --populationMap.end();
	populationMap.erase(iter);
	 
     //// output the size of the map
	cout << "Size of populationMap: " << populationMap.size() << '\n';
	
	for (iter = populationMap.begin(); iter != populationMap.end(); ++iter) 
	{
	 cout << iter->first <<":" << iter->second << " million\n";
	}
	
	char c;
	do
	{
		string state;
		cout<<"\nEnter that state you want to know the population of: ";
		cin>>state;
		iter = populationMap.find(state);
		if( iter != populationMap.end() ) 
		    cout << state <<"'s populations is "
		        << iter->second << " million\n";
		else
		    cout << "State is not in populationMap" << '\n';
		    
		cout<<"Do you wish to continue?(y/n):";
		cin>>c;
	}while(c=='y'||c=='Y');
	 
	populationMap.clear();
	
	return 0;
}