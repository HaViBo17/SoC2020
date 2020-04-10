/*
Harsh Vinayak Borkar 190070027
Logic:
Maintain two priority queues A and C 
A will give priority to lesser arrival date 
C will give priority to more curse 
start the counting of days and as the teacher is arrivied 
transfer it from A to C
*/
#include <iostream>
#include <queue>
using namespace std;
struct Teacher{
	int arrival ;
	int lectures ;
	int curse ;
	Teacher(int a , int b , int c ){
		arrival = a ;
		lectures = b ;
		curse = c ;
	}
};
struct CompareArrival{
	bool operator()(Teacher const& t1 , Teacher const& t2){
		return t1.arrival > t2.arrival;
	}
};
struct CompareCurse{
	bool operator()(Teacher const& t1 , Teacher const& t2){
		return t1.curse < t2.curse ;
	}
};
int main(){
	int n , d ;
	cin >> n >> d ;
	priority_queue<Teacher , vector<Teacher> , CompareArrival>A;
	priority_queue<Teacher , vector<Teacher> , CompareCurse>C;
	for(int i = 0 ; i < n ; i++){
		int a, b ,c;
		cin >> a >> b >> c ;
		A.push(Teacher(a,b,c));
	}
	for(int i = 1 ; i <= d ;i++){
		if(A.top().arrival == i){
			for(int j = 0 ; j < A.top().lectures ; j++)C.push(A.top());
			A.pop();
			continue;
		}
		if(!C.empty())C.pop();
	}
	int curse = 0 ;
	while(!C.empty()){
		curse += C.top().curse;
		C.pop();
	}
	cout << curse << endl;
}
