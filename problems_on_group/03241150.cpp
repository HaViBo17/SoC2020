/*
Harsh Vinayak Borkar 190070027
Logic :
when the king is at (r,c) then in k moves it can transverse in a rectangle 
with corners defined by (r-k,c-k) , (r-k,c+k) , (r+k,c-k) and (r+k,c+k)
*/
#include<iostream>
using namespace std ; 
bool check_inside_board(int r, int c ){
	if(r > 0 && r < 9 && c > 0 && c < 9)return 1;
	return 0;
}
int main (){
	int t ;
	cin >> t ;
	while(t--){
		int r ,c ,k ;
		cin >> r >> c >> k;
		int left_end , right_end , top_end , bottom_end;
		if(r-k > 0)left_end = r-k ;
		else left_end = 1 ;
		if(r+k < 9 )right_end = r+k ;
		else right_end = r+k ;
		if(c-k > 0)bottom_end = r-k ;
		else bottom_end = 1 ;
		if(c+k < 9 )top_end = r+k ;
		else top_end = r+k ;
		cout << (top_end - bottom_end + 1)*(right_end - left_end + 1) << endl;
	}
}
