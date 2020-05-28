#include<iostream>
#include<string>
#include<cctype>
#include<cstdlib>

#include "doubleLinkedList.cpp"
 
using namespace std;

string repeat();
bool isNumber(string);
 
int main() {
    DoubleLinkedList obj;
  	int option;
  	int key1, k1, data1;
  	
  	do{
    	cout<<"|		  Menu			|"<<endl;
		cout<<"\n0.- Out. \n1.- Insert Last. \n2.- Insert First. \n3.- Insert Before. \n4.- Insert After. \n5.- Insert At. \n6.- Extract. \n7.- Print Linked List. \n8.- Search. \n9.- Update Value. \n10.- Specific Delete. \n11.- Clear Linked List."<<endl;
		cout<<"\nType the require option: "<<endl;
    	option = atoi(repeat().c_str());
    	
    	switch(option) {
    		case 0:
    			cout<<"\nIt has exited, press twice any key to close the program.";
      		break;
    		case 1:
      			cout<<"Type the value to add at last: "<<endl;
      			data1 = atoi(repeat().c_str());
      			obj.insertLast(data1);
      		break;
    		case 2:
      			cout<<"Type the value to add at first: "<<endl;
      			data1 = atoi(repeat().c_str());
      			obj.insertFirst(data1);
      		break;
      		case 3:
      			cout<<"Type the value to search: "<<endl;
      			k1 = atoi(repeat().c_str());
      			cout<<"Type the value to add before: "<<endl;
      			data1 = atoi(repeat().c_str());
      			obj.insertBefore(k1,data1);
      		break;
    		case 4:
      			cout<<"Type the value to search: "<<endl;
      			k1 = atoi(repeat().c_str());
      			cout<<"Type the value to add after: "<<endl;
      			data1 = atoi(repeat().c_str());
      			obj.insertAfter(k1,data1);
      		break;
      		case 5:
      			cout<<"Type the index: "<<endl;
      			k1 = atoi(repeat().c_str());
      			cout<<"Type the value to add: "<<endl;
      			data1 = atoi(repeat().c_str());
      			obj.insertAt(k1,data1);
      		break;
      		case 6:
      			obj.extract();
      		break;
      		case 7:
      			obj.toString();
      		break;
      		case 8:
      			cout<<"Type de value to search: "<<endl;
      			k1 = atoi(repeat().c_str());
      			obj.search(k1);
      		break;
      		case 9:
      			cout<<"Update value: "<<endl;
      			key1 = atoi(repeat().c_str());
      			cout<<"To value: "<<endl;
      			data1 = atoi(repeat().c_str());
      			obj.updateValueByKey(key1,data1);
      		break;
      		case 10:
      			cout<<"Type the value to delete: "<<endl;
      			k1 = atoi(repeat().c_str());
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
	int length = numberString.size();	
	if(length==0||(length==1&&!isdigit(numberString[0]))){
		return false;
	}else{
		int var;
		while(var<length){
			if(!isdigit(numberString[var])){
				return false;
				break;
			}
			var++;
		}
	}
	return true;
}
