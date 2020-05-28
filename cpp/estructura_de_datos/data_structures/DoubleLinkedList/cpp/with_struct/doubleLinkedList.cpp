#include "doubleLinkedList.h"
#include <stdlib.h>
 
using namespace std;
 
DoubleLinkedList::DoubleLinkedList() {
    head = NULL;
}

bool DoubleLinkedList::contains(int key) {
   	Node *ptr = head;
   	while(ptr!=NULL) {
   		if(ptr->getData()==key) {
       		return true;
   		}
   		ptr = ptr->getNext();
   	}
   	return false;
}

bool DoubleLinkedList::isEmpty() {
  	if(head==NULL){
  		return true;
  	}else{
  		return false;
  	}
}
    
void DoubleLinkedList::insertLast(int data) {
    if(contains(data)) {
      	cout<<"\nValue exists. Insert at last another value.\n"<<endl;
    }else {
    	Node *node = new Node(data);
      	if(isEmpty()) {
        	head = node;
        	cout<<"\nValue has been added at last succesfully.\n"<<endl;
      	}else {
        	Node *ptr = head;
       		while(ptr->getNext()!=NULL) {
       			ptr = ptr->getNext();
       		}
       		ptr->setNext(node);
       	 	node->setPrevious(ptr);
       		cout<<"\nValue has been added at last succesfully.\n"<<endl;
      	}
    }
}

void DoubleLinkedList::insertFirst(int data){
	if(contains(data)) {
      	cout<<"\nValue exists. Insert at first another value.\n"<<endl;
   	}else {
   		Node *node = new Node(data);
    	if(isEmpty()) {
       		head = node;
       		cout<<"\nValue has been added at fist succesfully.\n"<<endl;
     	}else {
     		head->setPrevious(node);
       		node->setNext(head);
       		head = node;
       		cout<<"\nValue has been added at first succesfully.\n"<<endl;
     	}
	}
}

void DoubleLinkedList::insertBefore(int key,int data) {
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
      				if(ptr->getData()==key) {
        				break;
      				}
      				ptr = ptr->getNext();
    			}
      			Node *node = new Node();
				node->setData(data);
        		if(ptr->getPrevious()==NULL) {
        			insertFirst(data);	
        		}else {
        			Node *previousNode = ptr->getPrevious();
        			if(previousNode==NULL) {
          				ptr->setPrevious(node);
          				node->setNext(ptr);
          				cout<<"\nValue has been added before succesfully.\n"<<endl;
        			}else {
          				node->setPrevious(previousNode);
          				previousNode->setNext(node);
          				node->setNext(ptr);
          				ptr->setPrevious(node);
        				cout<<"\nValue has been added before succesfully.\n"<<endl;
        			}
       			}
     		}
    	}
    }
}

void DoubleLinkedList::insertAfter(int key,int data) {
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
      				if(ptr->getData()==key) {
        				break;
      				}
      				ptr = ptr->getNext();
    			}
      			Node *node = new Node();
				node->setData(data);
       	 		Node *nextNode = ptr->getNext();
       			if(nextNode==NULL) {
          			ptr->setNext(node);
          			node->setPrevious(ptr);
          			cout<<"\nValue has been added after succesfully.\n"<<endl;
        		}else {
          			node->setNext(nextNode);
          			nextNode->setPrevious(node);
         	 		node->setPrevious(ptr);
         	 		ptr->setNext(node);
         	 		cout<<"\nValue has been added after succesfully.\n"<<endl;
        		}
      		}
    	}
    }
}

void DoubleLinkedList::deleteValueByKey(int key) {
    if(!contains(key)) {
      	cout<<"\nValue doesn't exist.\n"<<endl;
    }else {
    	Node *ptr = head;
    	while(ptr!=NULL) {
      		if(ptr->getData()==key) {
        		break;
      		}
      		ptr = ptr->getNext();
    	}
      	if(head->getData()==key) {
        	head->setNext(head->getNext());
        	cout<<"\nValue has been deleted succesfully.\n"<<endl;
      	}else {
        	Node *nextNode = ptr->getNext();
        	Node *prevNode = ptr->getPrevious();
        	if(nextNode==NULL) { 
        		prevNode->setNext(NULL);
       			cout<<"\nValue has been deleted succesfully.\n"<<endl;
        	}else {
        		prevNode->setNext(nextNode);
        		nextNode->setPrevious(prevNode);
        		cout<<"\nValue has been deleted succesfully.\n"<<endl;
        	}
      	}
    }
}

void DoubleLinkedList::insertAt(int i,int data){
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
      					key = ptr->getData();
      					break;
      				}
      				var++;
      				ptr = ptr->getNext();
    			}
    			insertBefore(key,data);
      		}else{
      			insertFirst(data);
      		}
      	}
    }		
}

void DoubleLinkedList::updateValueByKey(int key,int data) {
  	if(isEmpty()) {
  		cout<<"\nDouble Linked List is empty.\n"<<endl;
  	}else {
  		if(!contains(key)){
  			cout<<"\nValue doesn't exist.\n"<<endl;
  		}else{
  			Node *ptr = head;
    		while(ptr!=NULL) {
   				if(ptr->getData()==key) {
   					ptr->setData(data);
      			cout<<"\nValue has been updated successfully\n"<<endl;
   	    			break;
   		 		}
   		 		ptr = ptr->getNext();
   		 	}
  		}
    }
}
 
bool DoubleLinkedList::search(int key){
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
	
void DoubleLinkedList::extract(){
	if(isEmpty()) {
  		cout<<"\nDouble Linked List is empty."<<endl;
  	}else {
  		Node *temp = head;
  		int value = head->getData();
  		head = head->getNext();
  		free(temp);		
       	cout<<"\nYour value has been extracted: "<<value<<"."<<endl;
  	}
}
 
void DoubleLinkedList::toString(){
	if(isEmpty()) {
      	cout<<"\nDouble Linked List is empty.\n"<<endl;
    }else {
    	Node *temp = head;
      	if(temp->getNext()==NULL) {
      		cout<<"\nDouble Linked List Value: \n\n{";
      	}else{
      		cout<<"\nDouble Linked List Values: \n\n{";
      	}
      	while(temp!=NULL) {
      		if(temp->getNext()==NULL) {
      			cout<<temp->getData();
      		}else {
      			cout<<temp->getData()<<",";
      		}
        	temp = temp->getNext();
      	}
      	cout<<"}\n\n";
    }
}
 
void DoubleLinkedList::clear(){
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
  				head = head->getNext() ;
  				free(temp);
  			}
  		}
  	}
}
