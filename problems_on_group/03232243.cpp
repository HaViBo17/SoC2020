/*
Harsh Vinayak Borkar 190070027
Logic :
*	suppose the array does not contain any odd number , then all the elements will be even
	and the second person wins the game 
*	if there exist an odd number in the array then there are two cases
		*the sum of elements is odd , then the first player removes all the elements and wins.
		
		*the sum of elements is even , then when the 2nd player is done playing his move the
		 sum of the remaining elements is odd
*/

#include <iostream>
using namespace std ;
int main(){
	int n ;
	cin >> n ;
	bool odd_found = 0 ;
	for(int i = 0 ; i < n ; i++){
		int temp ;
		cin >> temp ;
		if(temp%2)odd_found = 1;
	}
	bool first_wins = 1;
	if(!odd_found)first_wins = 0;
	if(first_wins)cout << "First";
	else cout << "Second" ;
}
