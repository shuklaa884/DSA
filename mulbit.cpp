#include<iostream>
using namespace std;

void update(int x,int val, int BIT[],int n){
	while(x<=n){
		BIT[x] *= val;
		x += x & -x;
	}
}

int query(int x,int BIT[]){
	int prod = 1;

	while(x>0)
	{
		prod *= BIT[x];

		x -= x & -x;
	}

	return prod;
}

int main(){

	int n; cin>>n;
	int *BIT = new int[n+1];
	
	for(int i=0;i<=n;i++)
		BIT[i] = 1;
	
	for (int i = 1;i<= n;i++){
		int t; cin>>t;
		update(i,t,BIT,n);
	}

	cout << query(3,BIT);
	for(int i=0;i<=n;i++)
		cout << BIT[i] <<"\t";

}