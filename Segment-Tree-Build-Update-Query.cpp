//Code never lies, LET'S START
//Author: Habib

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
     
#define  ll                long long int
#define  ff                first
#define  ss                second
#define  pb                push_back
#define  all(x)            x.begin(),x.end()
#define  loop(i,a,b)       for( ll i=a;i<b;i++ )
#define  loop2(i,b,a)      for( ll i=b;i>=a;i-- )
#define  mod               1000000007
#define  vll               vector<ll>
#define  vint              vector<int>
#define  pll               pair<ll,ll>
#define  vp                vector<pll>
#define  FastIO            ios_base::sync_with_stdio(false); cin.tie(NULL);
#define  ed                cout<<"\n";

const   ll    N = 2e5 + 5;
const   ll     inf = 1e18;

int test = 1 ;
int seg[N<<2][3] , lazy[N<<2] ;		// In this initialy i take a 2D seg array and 1D lazy array to keep value

// Rotate the array one times
void swap1( int &a , int &b , int &c ){
	int z = a ;
	int o = b ;
	int t = c ;
	a = t ;
	b = z ;
	c = o ;
}
// Rotate this array two times
void swap2( int &a , int &b , int &c ){
	int z = a ;
	int o = b ;
	int t = c ;
	a = o ;
	b = t ;
	c = z ;
}

// Handle the lazy operation and rotate
void propagate( int at , int low , int high ){
	if( low != high ){		//  transfering the ith value in next child
		lazy[2*at+1] = (lazy[at]+lazy[2*at+1]) % 3 ;
		lazy[2*at+2] = (lazy[at]+lazy[2*at+2]) % 3 ;
	}
	if( lazy[at] == 1 ){
		swap1( seg[at][0] , seg[at][1] , seg[at][2] ) ;
	}
	else if( lazy[at] == 2 ){
		swap2( seg[at][0] , seg[at][1] , seg[at][2] ) ;
	}
	lazy[at] = 0 ;
}

// Building the array
void Build( int at , int low , int high ){
	if( low == high ){
		seg[at][0] = 1 ;             // Initially its already divisible
		seg[at][1] = seg[at][2] = 0 ;
		return ;
	}
	int mid = (low+high) >> 1 ;
	Build( 2*at + 1 , low , mid ) ;
	Build( 2*at + 2 , mid+1 , high ) ;

	seg[at][0] = seg[at<<1 | 1][0] + seg[at<<1 | 2][0] ;
	seg[at][1] = seg[at][2] = 0 ;
}

// Update the array in this given range L-R
void Update( int at , int low , int high , int l , int r ){
	if( lazy[at] )
		propagate( at , low , high ) ;

	if( low>r or high<l )		return;

	if( low>=l and high<=r ){
		if( low != high ){
			lazy[2*at+1] = (1+lazy[2*at+1]) % 3 ;
			lazy[2*at+2] = (1+lazy[2*at+2]) % 3 ;
		}
		swap1( seg[at][0] , seg[at][1] , seg[at][2] ) ;
		return;
	}

	int mid = (low+high) >> 1; 

	Update( 2*at+1 , low , mid , l , r ) ;
	Update( 2*at+2 , mid+1 , high , l , r ) ;

	seg[at][0] = seg[2*at+1][0] + seg[2*at+2][0] ;
	seg[at][1] = seg[2*at+1][1] + seg[2*at+2][1] ;
	seg[at][2] = seg[2*at+1][2] + seg[2*at+2][2] ;
}

int Query( int at , int low , int high , int l , int r ){
	if( lazy[at] )
		propagate( at , low , high ) ;
	if( low>r or high<l )	return 0 ;

	if( low>=l and high<=r )
		return seg[at][0] ;

	int mid = (low+high) >> 1 ;
	return Query( 2*at+1 , low , mid , l , r ) +
		   Query( 2*at+2 , mid+1 , high , l , r ) ;
}

// Reset the seg 2D array and lazy array because of the other test case operation
void reset(){
	loop( i , 0 , 4*N ){
		seg[i][0] = seg[i][1] = seg[i][2] = 0 ;
		lazy[i] = 0 ;
	}
}

void pipra(){
	cout<< "Case " << (test++) << ":\n" ;
    int n,q;	cin>>n>>q;

    reset() ;
    Build( 0 , 0 , n-1 ) ;

    while( q-- ){
    	int check,left,right;	cin>>check>>left>>right;
    	if( check==0 ){
    		Update( 0 , 0 , n-1 , left , right ) ;
    	}
    	else{
    		int ans = Query( 0 , 0 , n-1 , left , right )  ;
    		cout<< ans << endl ;
    	}
    }
}
     
int main(){
    //Code_by_Habib
    FastIO;
    int tt;    cin>>tt;
    while(tt--)
        pipra();
    return 0;
}