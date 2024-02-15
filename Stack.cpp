/*
	Date: 	08-02-2024
	Author: Habib
	I have to do
	-> convert Infix to Postfix
	-> solve this Postfix
	-> print the result
*/

#include<bits/stdc++.h>
using namespace std;


// For evaluation Postfix
int precedence( int a , int b , char ch ) ;
int evaluationPost( string s ) ;

// For Converting Infix to Postfix
int preced( char ch ) ;
string inToPost( string s ) ;



int main(){
	//For Postfix
	string s = "456*+" ;
	cout<< "The result after evaluation Postfix: " << evaluationPost( s ) << endl;

	// Convert infix to postfix
	string infix = "x^y/(5*z)+2";
	cout<< "The string after Infix to Postfix: " << inToPost( infix ) <<endl;
	
	return 0 ;
}




// Which operation do compare to operator
int precedence( int a , int b , char ch ){
	if( ch == '+' )
		return b + a ;
	else if( ch == '-' )
		return b - a ;
	else if( ch == '*' )
		return b * a ;
	else if( ch == '/' )
		return b / a ;
	else if( ch == '^' )
		return pow( b , a ) ;
	return 0 ;
}
//Evaluaiton Postfix
int evaluationPost( string s ){
	stack<int> stk ;

	for( auto ch : s ){
		if( ch>='0' and ch<='9' ){
			stk.push( ch - '0' ) ;
		}
		else{
			int a = stk.top();
			stk.pop() ;
			int b = stk.top();
			stk.pop() ;

			int res = precedence ( a , b , ch ) ;
			stk.push( res ) ;
		}
	}

	return stk.top() ;
}

// Preced for converting Infix to Postfix
int preced( char ch ){
	if( ch == '+' or ch == '-' )
		return 1 ;
	else if( ch == '*' or ch == '/' )
		return 2 ;
	else if( ch == '^' )
		return 3 ;
	return 0 ;
}
// Convert Infix to Postfix
string inToPost( string s ){
	string postfix = "" ;
	stack<char> stk ;

	for( char ch : s ){
		if( isalnum( ch ) )
			postfix += ch ;
		else if( ch == '(' )
			stk.push( ch ) ;
		else if( ch == '^' )
			stk.push( ch ) ;
		else if( ch == ')' ){
			while( !stk.empty() and stk.top() != '(' ){
				postfix += stk.top() ;
				stk.pop() ;
			}
			stk.pop() ;
		}
		else{
			if( preced(ch) > preced(stk.top()) ){
				stk.push( ch ) ;
			}
			else{
				while( !stk.empty() and ( preced(ch) <= preced(stk.top()) ) ){
					postfix += stk.top() ;
					stk.pop() ;
				}
				stk.push( ch ) ;
			}
		}
	}

	while( !stk.empty() ){
		postfix += stk.top() ;
		stk.pop() ;
	}

	return postfix ;
}

