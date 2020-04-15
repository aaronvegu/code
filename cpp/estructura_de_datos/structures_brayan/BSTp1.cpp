#include<iostream>
#include<stdlib.h>

struct Node{  
	int key;
	int height;   
    Node *left;  
    Node *right;   
};  

Node *root = NULL;
Node *root1 = NULL;

bool contains(Node* root,int key){
	if(root==NULL){
		return false;
	}else if(key<root->key){
		contains(root->left,key);
	}else if(key>root->key){
		contains(root->right,key);
	}else{
		if(root->key==key){
			return true;
		}else if(root->left==NULL){
			return false;
		}else if(root->right==NULL){
			return false;
		}else{
			return false;
		}
	}
}  

int height(Node *node){  
    if(node==NULL){
    	return 0; 
    }else{
    	return node->height; 
    } 
}  

int max(int a,int b){  
    return (a>b)?a:b;  
}   

int getBalance(Node *node){  
    if(node==NULL){
    	return 0;  
    }else{
    	return height(node->left) - height(node->right);  
    }
}  
  
Node* newNode(int key){  
    Node* node = new Node(); 
    node->key = key;  
    node->left = NULL;  
    node->right = NULL;  
    node->height = 1; 
    return node;  
}  
   
Node* rightRotate(Node *node){  
    Node *x = node->left;  
    Node *aux = x->right;  
    x->right = node;  
    node->left = aux;  
    node->height = max(height(node->left),height(node->right)) + 1;  
    x->height = max(height(x->left),height(x->right)) + 1;  
    return x;  
}  
  
Node* leftRotate(Node *node){  
    Node *y = node->right;  
    Node *aux = y->left;  
    y->left = node;  
    node->right = aux;  
    node->height = max(height(node->left),height(node->right)) + 1;  
    y->height = max(height(y->left),height(y->right)) + 1;  
    return y;  
}  

Node* insert(Node* node,int key){  
    if(node==NULL){
    	return(newNode(key));  	
    }else if(!contains(node,key)){
    	if(key<node->key){
        	node->left = insert(node->left,key);  
    	}else if(key>node->key){
        	node->right = insert(node->right,key);  
    	}else{
        	return node; 
		}
  
    	node->height = 1 + max(height(node->left),height(node->right));  
    	int balance = getBalance(node);  
  
    	if(balance>1&&key<node->left->key){
        	return rightRotate(node);
		}else if(balance<-1&&key>node->right->key){
        	return leftRotate(node);  
    	}else if(balance>1&&key>node->left->key){	  
        	node->left = leftRotate(node->left);  
        	return rightRotate(node);  
    	}else if(balance<-1&&key<node->right->key){  
        	node->right = rightRotate(node->right);  
        	return leftRotate(node);  
    	} 
    }  
    return node;  
}  

Node* getMin(Node* root){   
    while(root->left!=NULL){
    	root = root->left; 	
    }   
    return root;  
}  

Node* deleteNode(Node* root,int key){   
    if(root==NULL){
    	return root; 
    }else if(contains(root,key)){
    	if(key<root->key){
        	root->left = deleteNode(root->left,key);  
    	}else if(key>root->key){
        	root->right = deleteNode(root->right,key);  
    	}else{	  
        	if((root->left==NULL)||(root->right==NULL)){  
            	Node *temp = root->left?root->left:root->right;  
            	if(temp==NULL){  
                	temp = root;  
                	root = NULL;  
            	}  
            	else{
            		*root = *temp;
				}
            	free(temp);  
        	}  
        	else{   
            	Node* temp = getMin(root->right);  
            	root->key = temp->key;  
            	root->right = deleteNode(root->right,temp->key);  
        	}		  
    	}  
    	if(root==NULL){
    		return root;
		}else{
			root->height = 1 + max(height(root->left),height(root->right));   
    		int balance = getBalance(root);  
  
    		if(balance>1&&getBalance(root->left)>=0){
        		return rightRotate(root);  
  			}else if(balance>1&&getBalance(root->left)<0){  
        		root->left = leftRotate(root->left);  
        		return rightRotate(root);  
    		}else if(balance<-1&&getBalance(root->right)<=0) {
       		 	return leftRotate(root);  
  			}else if(balance<-1&&getBalance(root->right)>0){  
        		root->right = rightRotate(root->right);  
        		return leftRotate(root);  
    		} 
		} 
    }
    return root;  
} 

void preOrder(Node *root){  
    if(root!=NULL){  
        std::cout<<root->key<<" ";  
        preOrder(root->left);  
        preOrder(root->right);  
    }  
}  

void inOrder(Node *root) {
   	if(root!=NULL){
   		inOrder(root->left);
      	std::cout<<root->key<<" ";
      	inOrder(root->right);	
   	}
}

void postOrder(Node *root) {
   	if(root!=NULL){
      	postOrder(root->left);
      	postOrder(root->right);
      	std::cout<<root->key<<" ";
  	}
}

int main(){
	root = newNode(4);
	
	root = insert(root,2);
	root = insert(root,6);
	root = insert(root,1);
	root = insert(root,3);
	root = insert(root,5);
	root = insert(root,7);
	
	std::cout<<"Entrada del arbol de manera que no requiera de rotaciones.\n\nIn-Order\n\n";
	inOrder(root);
	std::cout<<"\n";
	std::cout<<"\nPost-Order\n\n";
	postOrder(root);
	std::cout<<"\n";
	std::cout<<"\nPre-Order\n\n";
	preOrder(root);
	std::cout<<"\n";
	
	root1 = newNode(7);
	
	root1 = insert(root1,6);
	root1 = insert(root1,5);
	root1 = insert(root1,4);
	root1 = insert(root1,3);
	root1 = insert(root1,2);
	root1 = insert(root1,1);
	
	std::cout<<"\nEntrada del arbol de manera que requiera de rotaciones. \n\nIn-Order\n\n";
	inOrder(root1);
	std::cout<<"\n";
	std::cout<<"\nPost-Order\n\n";
	postOrder(root1);
	std::cout<<"\n";
	std::cout<<"\nPre-Order\n\n";
	preOrder(root1);
	std::cout<<"\n";
	
	root1 = deleteNode(root1,4);	
	
	std::cout<<"\nEntrada del arbol de manera que requiera de rotaciones y con borrado de la raiz. \n\nIn-Order\n\n";
	inOrder(root1);
	std::cout<<"\n";
	std::cout<<"\nPost-Order\n\n";
	postOrder(root1);
	std::cout<<"\n";
	std::cout<<"\nPre-Order\n\n";
	preOrder(root1);
	std::cout<<"\n";
	
	root1 = insert(root1,4);	
	
	std::cout<<"\nEntrada del arbol de manera que requiera de rotaciones y con insercion del valor 4 que no sera raiz, ya que no interfiere directamente con el acomodo de los valores en dicho momento. \n\nIn-Order\n\n";
	inOrder(root1);
	std::cout<<"\n";
	std::cout<<"\nPost-Order\n\n";
	postOrder(root1);
	std::cout<<"\n";
	std::cout<<"\nPre-Order\n\n";
	preOrder(root1);
	std::cout<<"\n";
	
	
	return 0;
}

