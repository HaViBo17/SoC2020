/*
Harsh Vinayak Borkar 190070027
Logic :
while storing the array we shall also store the index of the element 
using multidimensional array
then , sort the array using merge sort 
begin the operations from the beginning of the array
taking only the non-negative elements
*/
#include <iostream>
#include <vector>
using namespace std ;
void merge(vector<vector<int> > a, int n_a ,vector<vector<int> > b, int n_b ,vector<vector<int> > &data){
	int x = 0 , y = 0 ;
	for(int i = 0 ; i < n_a + n_b ; i++){
		if(x < n_a && y < n_b){
			if(a[x][0] <= b[y][0]){
				data[i][0] = a[x][0];
				data[i][1] = a[x][1];
				x++;
			}else{
				data[i][0] = b[y][0];
				data[i][1] = b[y][1];
				y++;
			}
		}else if(x < n_a){
			data[i][0] = a[x][0];
			data[i][1] = a[x][1];
			x++;
		}else{
			data[i][0] = b[y][0];
			data[i][1] = b[y][1];
			y++;
		}
	}
}
void merge_sort(vector<vector<int> > &data , int n){
	if(n == 1)return ;
	vector<vector<int> > a(n/2 , vector<int>(2));
	vector<vector<int> > b(n - n/2, vector<int>(2));
	for(int i = 0 ; i < n/2 ; i++){
		a[i][0] = data[i][0];
		a[i][1] = data[i][1];
	}
	for(int i = 0 ; i < n - n/2 ; i++){
		b[i][0] = data[i + n/2][0];
		b[i][1] = data[i + n/2][1];
	}
	merge_sort(a , n/2);
	merge_sort(b , n - n/2);
	merge(a, n/2 , b , n - n/2 , data);
}
int main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n;
		vector<vector<int> > data(n , vector<int>(2));
		for(int i = 1 ; i <= n ;i++){
			cin >> data[i-1][0];
			data[i-1][1] = i  ;
		}
		merge_sort(data , n);
		int key = 0 , operations = 0;
		while(1){
			if(data[key][0] < 0){
				key++;
				if(key >= n)break;
				else continue;
			}
			int operations_inc = data[key][0] / data[key][1] + 1 ;
			operations += operations_inc ;
			for(int i = key ; i < n ; i++)data[i][0] -= data[key][1] * operations_inc ;
		}
		cout << operations << endl;
	}
}
