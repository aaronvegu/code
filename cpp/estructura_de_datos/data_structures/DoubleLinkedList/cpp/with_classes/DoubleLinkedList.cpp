#include<iostream>
#include<stdlib.h>
#include<string>
#include<cctype>
#include<cstdlib>
 
using namespace std;

string repeat();
bool isNumber(string);
 
class Node {
  	public:
  		int data;
  		Node *next;
  		Node *previous;
 
  	Node() {
    	data = 0;
    	next = NULL;
    	previous = NULL;
  	}
  	Node(int &data) {
    	data = data;
  	}
};
 
class doubleLinkedList {
  	public:
    	Node *head;
 
  	doubleLinkedList() {
    	head = NULL;
  	}
  	doubleLinkedList(Node *node) {
    	head = node;
  	}
  	
  	bool contains(int key) {
    	Node *ptr = head;
    	while(ptr!=NULL) {
      		if(ptr->data==key) {
        		return true;
      		}
      		ptr = ptr->next;
    	}
    	return false;
  	}
  	bool isEmpty() {
  		if(head==NULL){
  			return true;
  		}else{
  			return false;
  		}
  	}
  	void insertLast(int data) {
    	if(contains(data)) {
      		cout<<"\nValue exists. Insert at last another value.\n"<<endl;
    	}else {
    		Node *node = new Node();
			node->data = data;
      		if(isEmpty()) {
        		head = node;
        		cout<<"\nValue has been added at last succesfully.\n"<<endl;
      		}else {
        		Node *ptr = head;
        		while(ptr->next!=NULL) {
          			ptr = ptr->next;
        		}
        		ptr->next = node;
       		 	node->previous = ptr;
        		cout<<"\nValue has been added at last succesfully.\n"<<endl;
      		}
    	}
  	}
  	void insertFirst(int data) {
    	if(contains(data)) {
      		cout<<"\nValue exists. Insert at first another value.\n"<<endl;
   	 	}else {
   	 		Node *node = new Node();
			node->data = data;
      		if(isEmpty()) {
        		head = node;
        		cout<<"\nValue has been added at fist succesfully.\n"<<endl;
      		}else {
       	 		head->previous = node;
        		node->next = head;
        		head = node;
        		cout<<"\nValue has been added at first succesfully.\n"<<endl;
      		}
    	}
  	}
  	void insertBefore(int key,int data) {
    	if(isEmpty()) {
    		insertFirst(data);
    	}else {
    		if(!contains(key)) {
      			cout<<"\nValue doesn't exist.\n"<<endl;
    		}else {
      			if(contains(data)) {
        			cout<<"\nValue exists. Insert at first another value.\n"<<endl;
      			}else {
    				Node *ptr = head;
    				while(ptr!=NULL) {
      					if(ptr->data==key) {
        					break;
      					}
      					ptr = ptr->next;
    				}
      				Node *node = new Node();
					node->data = data;
        			if(ptr->previous==NULL) {
        				insertFirst(data);	
        			}else {
        				Node *previousNode = ptr->previous;
        				if(previousNode==NULL) {
          					ptr->previous = node;
          					node->next = ptr;
          					cout<<"\nValue has been added before succesfully.\n"<<endl;
        				}else {
          					node->previous = previousNode;
          					previousNode->next = node;
          					node->next = ptr;
          					ptr->previous = node;
          					cout<<"\nValue has been added before succesfully.\n"<<endl;
        				}
        			}
      			}
    		}
    	}
  	}
  	void insertAfter(int key,int data) {
    	if(isEmpty()) { 
    		insertFirst(data);
    	}else {
    		if(!contains(key)) {
      			cout<<"\nValue doesn't exist.\n"<<endl;
    		}else {
      			if(contains(data)) {
        			cout<<"\nValue exists. Insert at last another value.\n"<<endl;
      			}else {
      				Node *ptr = head;
    				while(ptr!=NULL) {
      					if(ptr->data==key) {
        					break;
      					}
      					ptr = ptr->next;
    				}
      				Node *node = new Node();
					node->data = data;
       	 			Node *nextNode = ptr->next;
       		 		if(nextNode==NULL) {
          				ptr->next = node;
          				node->previous = ptr;
          				cout<<"\nValue has been added after succesfully.\n"<<endl;
        			}else {
          				node->next = nextNode;
          				nextNode->previous = node;
         	 			node->previous = ptr;
         	 			ptr->next = node;
         	 			cout<<"\nValue has been added after succesfully.\n"<<endl;
        			}
      			}
    		}
    	}
  	}
  	void deleteValueByKey(int key) {
    	if(!contains(key)) {
      		cout<<"\nValue doesn't exist.\n"<<endl;
    	}else {
    		Node *ptr = head;
    		while(ptr!=NULL) {
      			if(ptr->data==key) {
        			break;
      			}
      			ptr = ptr->next;
    		}
      		if(head->data==key) {
        		head = head->next;
        		cout<<"\nValue has been deleted succesfully.\n"<<endl;
      		}else {
        		Node *nextNode = ptr->next;
        		Node *prevNode = ptr->previous;
        		if(nextNode==NULL) { 
          			prevNode->next = NULL;
          			cout<<"\nValue has been deleted succesfully.\n"<<endl;
        		}else {
          			prevNode->next = nextNode;
          			nextNode->previous = prevNode;
          			cout<<"\nValue has been deleted succesfully.\n"<<endl;
        		}
      		}
    	}
  	}
  	void insertAt(int i,int data){
    	if(isEmpty()) {
      		if(i>0) {
      			cout<<"\nValue can't be added, because index "<<i<<" doesn't exist.\n"<<endl;
      		}else {
      			insertFirst(data);
      		}
    	}else {
      		if(contains(data)) {
        		cout<<"\nValue exists. Insert another value.\n"<<endl;
      		}else {
      			if(i>0){
      				int var = 0,key = 0;
    				Node *ptr = head;
    				while(ptr!=NULL) {
      					if(var==i) {
      						key = ptr->data;
      						break;
      					}
      					var++;
      					ptr = ptr->next;
    				}
    				insertBefore(key,data);
      			}else{
      				insertFirst(data);
      			}
      		}
    	}	
  	}
  	void updateValueByKey(int key,int data) {
  		if(isEmpty()) {
  			cout<<"\nDouble Linked List is empty.\n"<<endl;
  		}else {
  			Node *ptr = head;
    		while(ptr!=NULL) {
      			if(ptr->data==key) {
        			break;
      			}
      			ptr = ptr->next;
    		}
    		if(ptr!=NULL) {
      			ptr->data = data;
      			cout<<"\nValue has been updated successfully\n"<<endl;
    		}else {
    	  		cout<<"\nValue doesn't exist.\n"<<endl;
    		}
    	}
  	}
  	bool search(int key){
  		if(isEmpty()) {
  			cout<<"\nDouble Linked List is empty.\n"<<endl;
  		}else {
  			if(contains(key)) {
  				cout<<"\nValue has been found it.\n"<<endl;
  				return true;
  			}else{
  				cout<<"\nValue has not been found it.\n"<<endl;
  				return false;
  			}
  		}
  	}
  	int extract(){
  		if(isEmpty()) {
  			return -1;
  		}else {
  			Node *temp = head;
  			int value = head->data;
  			head = head->next;
  			free(temp);		
        	return value;
  		}
  	}
  	void toString() {
    	if(isEmpty()) {
      		cout<<"\nDouble Linked List is empty.\n"<<endl;
    	}else {
    		Node *temp = head;
      		if(temp->next==NULL) {
      			cout<<"\nDouble Linked List Value: \n\n{";
      		}else{
      			cout<<"\nDouble Linked List Values: \n\n{";
      		}
      		while(temp!=NULL) {
      			if(temp->next==NULL) {
      				cout<<temp->data;
      			}else {
      				cout<<temp->data<<",";
      			}
        		temp = temp->next;
      		}
      		cout<<"}\n\n";
    	}
  	}
  	void clear() { 
  		if(isEmpty()) {
  			cout<<"\nDouble Linked List is empty.\n"<<endl;
  		}else{
  			Node *temp = head;
  			while(temp!=NULL) {
  				if(isEmpty()) {
  					cout<<"\nDouble Linked List has been clear succesfully.\n"<<endl;
  					return;
  				}else{
  					Node *temp = head;
  					head = head->next;
  					free(temp);
  				}
  			}
  		}
  	}
};
 
int main() {
  	doubleLinkedList obj;
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
      			cout<<"\nExtracted value: "<<obj.extract()<<".\n"<<endl;
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
