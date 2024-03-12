#include<bits/stdc++.h>
using namespace std ;

struct node{
	int data ;
	struct node *leftchild , *rightchild ;
};

struct node *root = NULL ;     //Start node of tree

//Creating a newNode with his leftchild and rightchild
struct node* newNode( int data ){
   struct node *temp = (struct node*) malloc( sizeof(struct node) ) ;
   temp->data = data ;
   temp->leftchild = temp->rightchild = NULL ;
   return temp ;
}

//Function of inserting element in the tree
void insert( int data ){
   struct node *current ;
	struct node *parent ;
   struct node * tempNode = newNode( data ) ;

	if( root == NULL ){
		root = tempNode ;
	}
	else{
		current = root ;
		while( true ){
			parent = current ;
			if( data < parent->data ){
				current = parent->leftchild ;
				if( current == NULL ){
					parent->leftchild = tempNode ;
					return;
				}
			}
			else{
				current = parent->rightchild ;
				if( current == NULL ){
					parent->rightchild = tempNode ;
					return;
				}
			}
		}
	}
}

//Printing this tree
void printTree( struct node *curr ){
   if( curr == NULL )   
      return;
   printTree( curr->leftchild ) ;
   cout<< curr->data << "->" ; 
   printTree( curr->rightchild );
}

//Searching element int the tree
struct node* Search( int data ){
   struct node *curr = root ;
   while( curr->data != data ){
      if( curr->data > data )
         curr = curr->leftchild ;
      else if( curr->data < data )
         curr = curr->rightchild ;

      if( curr == NULL )
         return NULL ;
   }

   return curr ;
}

int main(){
   //Inserting element into the tree
	insert(55);
   insert(20);
   insert(90);
   insert(50);
   insert(35);
   insert(15);
   insert(65);

   //Print this tree
   printTree( root ) ;
   cout<<endl;

   //Searching element int the tree
   struct node *k ;
   k = Search( 35 ) ;
   cout<< (( k==NULL ) ? "Data Not Found" : "Data Found") ;   //Checking Found or Not 
   cout<<endl;
	return 0 ;
}