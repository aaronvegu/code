#include<iostream>
#include<string>
#include<sstream>
#include<cctype>
#include<cstdlib>

#include <list>
 
using namespace std;

string repeat();
bool isNumber(string);
 
int main() {
    list<int> obj;
  	int option;
  	int key1, k1, data1;
  	
  	do{
    	cout<<"|		  Menu			|"<<endl;
		cout<<"\n0.- Out. \n1.- Insert Last. \n2.- Insert First. \n3.- Insert Before. \n4.- Insert After. \n5.- Insert At. \n6.- Extract. \n7.- Print Linked List. \n8.- Search. \n9.- Update Value. \n10.- Specific Delete. \n11.- Clear Linked List."<<endl;
		cout<<"\nType the require option: "<<endl;
    	istringstream(repeat())>>option;
    	
    	switch(option) {
    		case 0:
    			cout<<"\nIt has exited, press twice any key to close the program.";
      		break;
    		case 1:
      			cout<<"Type the value to add at last: "<<endl;
      			istringstream(repeat())>>data1;
      			obj.insertLast(data1);
      		break;
    		case 2:
      			cout<<"Type the value to add at first: "<<endl;
      			istringstream(repeat())>>data1;
      			obj.insertFirst(data1);
      		break;
      		case 3:
      			cout<<"Type the value to search: "<<endl;
      			istringstream(repeat())>>k1;
      			cout<<"Type the value to add before: "<<endl;
      			istringstream(repeat())>>data1;
      			obj.insertBefore(k1,data1);
      		break;
    		case 4:
      			cout<<"Type the value to search: "<<endl;
      			istringstream(repeat())>>k1;
      			cout<<"Type the value to add after: "<<endl;
      			istringstream(repeat())>>data1;
      			obj.insertAfter(k1,data1);
      		break;
      		case 5:
      			cout<<"Type the index: "<<endl;
      			istringstream(repeat())>>k1;
      			cout<<"Type the value to add: "<<endl;
      			istringstream(repeat())>>data1;
      			obj.insertAt(k1,data1);
      		break;
      		case 6:
      			cout<<"\nValue extracted: "<<obj.extract()<<".\n"<<endl;
      		break;
      		case 7:
      			obj.toString();
      		break;
      		case 8:
      			cout<<"Type de value to search: "<<endl;
      			istringstream(repeat())>>k1;
      			obj.search(k1);
      		break;
      		case 9:
      			cout<<"Update value: "<<endl;
      			istringstream(repeat())>>key1;
      			cout<<"To value: "<<endl;
      			istringstream(repeat())>>data1;
      			obj.updateValueByKey(key1,data1);
      		break;
      		case 10:
      			cout<<"Type the value to delete: "<<endl;
      			istringstream(repeat())>>k1;
      			obj.deleteValueByKey(k1);
      		break;
      		case 11:
      			obj.clear();
      		break;
    		default: cout<<"\nError incorrect option, please type again a valid option.\n"<<endl;
    	}
  	}while(option!=0);
 
 	cin.get();
  	return 0;
}

string repeat(){
	string numberString;
	bool repeat = true;
	do{
		getline(cin,numberString);
		if(isNumber(numberString)){
			repeat = false;
		}
	}while(repeat);
	return numberString;
}
bool isNumber(string numberString){
	float valF;
	double valD;
	int valI;
	if(istringstream(numberString)>>valF){
		return true;
	}else if(istringstream(numberString)>>valD){
		return true;
	}else if(istringstream(numberString)>>valI){
		return true;
	}
	return false;
}
