/*
	Author: Habibur Rahman
	Github username: pipra
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data ;
	struct Node* next ;					//self referencing structure
};
Node* head = NULL ;						//head is a pointer and pointing a stuct Node of structure

/*
	All of the function before main (),
	implementation of this functions after main()
*/

//Insertion
void insertAtBegin( int value ) ;						//It's insert a element begin of the linked list
void insertAtMiddle( int checkValue , int value ) ;
void insertAtLast( int value ) ;

//Deletion
void deleteFromBegin() ;
void deleteFromMiddle( int checkValue ) ;
void deleteFromLast() ;

//Printing value of this linked list
void printInfo() ;

int main(){
	cout<<"Insert element at begin in a Linked List: \n" ;
	insertAtBegin( 5 ) ;
	insertAtBegin( 4 ) ;
	insertAtBegin( 3 ) ;
	insertAtBegin( 2 ) ;
	insertAtBegin( 1 ) ;
	printInfo() ;

	cout<<"Insert element at middle in a Linked List: \n" ;
	insertAtMiddle( 4 , 100 ) ;
	insertAtMiddle( 3 , 100 ) ;
	insertAtMiddle( 7 , 100 ) ;
	printInfo();

	cout<<"Insert element at last in a Linked List:\n" ;
	insertAtLast( 5 ) ;
	insertAtLast( 10 ) ;
	insertAtLast( 15 ) ;
	printInfo() ;

	cout<<"Delete a element from begin of the Linked List: \n" ;
	deleteFromBegin() ;
	deleteFromBegin() ;
	printInfo() ;

	cout<<"Delete a element from middle of the Linked List: \n" ;
	deleteFromMiddle( 5 ) ;
	deleteFromMiddle( 10 ) ;
	deleteFromMiddle( 16 ) ;
	printInfo();

	cout<<"Delete a element from last of the Linked List: \n" ;
	deleteFromLast();
	deleteFromLast();
	printInfo();

	return 0 ;
}


void printInfo(){
	Node* ptr = head ;
	if( ptr == NULL ){
		return;
	}
	while( ptr != NULL ){
		cout<< ptr->data << ' ' ;
		ptr = ptr->next ;
	}
	cout<<"\n" ;
}


void insertAtBegin( int value ){
	Node* ptr = head ;
	Node* newNode = (Node*) malloc( sizeof( struct Node ) ) ;
	newNode->data = value ;
	newNode->next = NULL ;
	if( ptr==NULL ){
		head = newNode ;
		return;
	}
	newNode->next = ptr ;
	head = newNode ;
}


void insertAtMiddle( int checkValue , int value ){
	Node* ptr = head ;
	if( ptr == NULL )		return ;
	while( ptr->data != checkValue  and  ptr->next != NULL )		ptr = ptr->next ;
	if( ptr->data == checkValue ){
		Node* newNode = (Node*) malloc( sizeof( struct Node ) ) ;
		newNode->data = value ;
		newNode->next = ptr->next ;
		ptr->next = newNode ;
	}
}


void insertAtLast( int value ){
	Node* ptr = head ;			//take a Node pointer and pointing it head
	Node* newNode = (Node*) malloc( sizeof( struct Node ) ) ;
	newNode->data = value ;
	newNode->next = NULL ;
	if( ptr==NULL){
		head = newNode ;
		return;
	}
	while( ptr->next != NULL )		ptr = ptr->next ;
	ptr->next = newNode ;
}


void deleteFromBegin(){
	if( head == NULL ){
		cout<<"No element have in this Linked List\n";
		return;
	}
	head = head->next ;
}


void deleteFromMiddle( int checkValue ){
	Node* ptr = head ;
	Node* prev = NULL ;
	if( ptr == NULL ){
		cout<<"No element have in this Linked List\n";
		return;
	}
	while( ptr->data != checkValue   and   ptr->next != NULL ){
		if( ptr != head ){
			prev = ptr ;
			ptr = ptr->next ;
		}
		else{
			ptr = ptr->next ;
		}
	}
	if( ptr->data == checkValue ){
		prev->next = ptr->next ;
	}
}


void deleteFromLast(){
	Node* ptr = head ;
	Node* prev = NULL ;
	if( ptr == NULL ){
		cout<<"No element have in this Linked List\n";
		return;
	}
	while( ptr->next != NULL ) {
		if( ptr != head ){
			prev = ptr ; 
			ptr = ptr->next ;
		}
		else{
			ptr = ptr->next ;
		}
	}

	if( prev == NULL ){
		head = NULL ;
		return ;
	}
	prev->next = NULL ;
}