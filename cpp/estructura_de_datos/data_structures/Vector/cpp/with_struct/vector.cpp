#include<iostream>
#include<stdlib.h>
#include<string>
#include<cctype>
#include<cstdlib>

using namespace std;

string repeat();
bool isNumber(string);

struct Node{
	int value;
	Node *next;
};

Node *head = NULL;
Node *tail = NULL;

void newNode(int value){
	Node *node = new Node();
	node->value = value;
	node->next = NULL;
	if(head==NULL){
		head = node;
		tail = node;
	}else{
		tail->next = node;
		tail = node;
	}
}
void buildVector(){
	for(int i=0;i<10;i++){
		newNode(-1);
	}
}
int capacity(){
	int i = 0;
	Node *current = head;
	while(current!=NULL){
		i++;
		current = current->next;
	}
	return i;
}
int size(){
	int i = 0;
	Node *current = head;
	while(current!=NULL){
		if(current->value!=-1){
			i++;	
		}
		current = current->next;
	}
	return i;
}
int freeAt(){
	int i = 0;
	Node *current = head;
	while(current!=NULL){
		if(current->value==-1){
			return i;
		}
		i++;
		current = current->next;
	}
	return i;
}
bool isFull(){
	Node *current = head;
	while(current!=NULL){
		if(current->value==-1){
			return false;	
		}
		current = current->next;
	}
	Node *node = head;
	while(node!=NULL){
		if(node->next==NULL){
			for(int i=0;i<5;i++){
				newNode(-1);
			}
			break;
		}
		node = node->next;
	}
	return true;
}
bool contains(int value){
	Node *current = head;
	while(current!=NULL){
		if(current->value==value){
			return true;
		}
		current = current->next;
	}
	return false;
}	
bool add(int value){
	if(isFull()){
		if(contains(value)){
			cout<<"\nYour value has not been add, because there exists."<<endl;
			return false;
		}else{
			Node *current = head;
			while(current!=NULL){
				if(current->value==-1){
					current->value = value;
					break;
				}
				current = current->next;
			}
			cout<<"\nYour value has been successfully added."<<endl;
			return true;
		}
	}else{
		if(contains(value)){
			cout<<"\nYour value has not been add, because there exists."<<endl;
			return false;
		}else{
			Node *current = head;
			while(current!=NULL){
				if(current->value==-1){
					current->value = value;
					break;
				}
				current = current->next;
			}
			cout<<"\nYour value has been successfully added."<<endl;
			return true;
		}
	}
}
int get(int i){
	int var = 0;
	Node *current = head;
	while(current!=NULL){
		if(var==i){
			return current->value;
		}
		var++;
		current = current->next;
	}
	return 0;
}
bool remove(int value){
	if(contains(value)){
		Node *current = head;
		while(current!=NULL){
			if(current->value==value){
				current->value = -1;
				break;
			}
			current = current->next;
		}
		cout<<"\nYour value has been successfully removed."<<endl;
		return true;
	}else{
		cout<<"\nYour value has not been removed, because there is not exists."<<endl;
		return false;
	}
}
bool removeAt(int i){
	int var = 0;
	Node *current = head;
	while(current!=NULL){
		if(var==i){
			if(current->value!=-1){
				current->value = -1;
				cout<<"\nYour value has been successfully removed."<<endl;
				return true;
			}else{
				cout<<"\nYour value has not been removed, because there is not exists."<<endl;
				return false;
			}
		}
		var++;
		current = current->next;
	}
	cout<<"\nYour value has not been removed, because there is not exists."<<endl;
	return false;
}
void toString(){
	Node *current = head;
	if(current->next==NULL){
		cout<<"\nThe value of the Vector is: \n\n{";
	}else{
		cout<<"\nThe values of the Vector are: \n\n{";
	}
	while(current!=NULL){
		if(current->next==NULL){
			cout<<current->value;
		}else{
			cout<<current->value<<",";
		}	
		current = current->next;
	}
	cout<<"}\n";
}	
void clear(){
	while(head!=NULL){
		Node *current = head;
		head = head->next;
		free(current);
	}
	buildVector();
	cout<<"\nThe Vector is clear successfully."<<endl;
}

int main(){
	buildVector();
	int option,value;
	bool out = false;
	do{
		cout<<"|		  Menu			|"<<endl;
		cout<<"\n0.- Out. \n1.- Add. \n2.- Get. \n3.- Remove. \n4.- Remove At. \n5.- Print Vector. \n6.- Capacity. \n7.- Size. \n8.- Free Space At. \n9.- Contains. \n10.- Is Full. \n11.- Clear."<<endl;
		cout<<"\nType the require option: "<<endl;
		option = atoi(repeat().c_str());
				
		switch(option){
			case 0:
				out = true;
				cout<<"\nIt has exited, press twice any key to close the program.";
			break;
			case 1:
				cout<<"\nType the value to add(integer): "<<endl;
				value = atoi(repeat().c_str());
				add(value);
			break;
			case 2:
				cout<<"\nType the index to get(integer): "<<endl;
				value = atoi(repeat().c_str());
				cout<<"\nThe value is: "<<get(value)<<"."<<endl;
			break;
			case 3:
				cout<<"\nType the value to remove(integer): "<<endl;
				value = atoi(repeat().c_str());
				remove(value);
			break;
			case 4:
				cout<<"\nType the index to remove(integer): "<<endl;
				value = atoi(repeat().c_str());
				removeAt(value);
			break;
			case 5:
				toString();	
			break;
			case 6:
				cout<<"\nCapacity of vector is: "<<capacity()<<endl;
			break;
			case 7:
				cout<<"\nSpaces on use: "<<size()<<endl;
			break;
			case 8:
				cout<<"\nFree space index at: "<<freeAt()<<endl;
			break;
			case 9:
				cout<<"\nType the value to search(integer): "<<endl;
				value = atoi(repeat().c_str());
				if(contains(value)){
					cout<<"\nThe value is on the vector."<<endl;
				}else{
					cout<<"\nThe value is not on the vector."<<endl;
				}
			break;
			case 10:
				if(isFull()){
					cout<<"\nVector is full."<<endl;
				}else{
					cout<<"\nVector has empty spaces."<<endl;
				}
			break;
			case 11:
				clear();
			break;
				
			default: cout<<"\nError incorrect option, please type again a valid option."<<endl;
		}
		cout<<"\n";
	}while(!out);
	
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