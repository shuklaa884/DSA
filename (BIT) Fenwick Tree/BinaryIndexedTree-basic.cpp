#include<iostream>
using namespace std;

void update(int x,int  val,int n, int BIT[])
{
	while(x<=n)
	{
		BIT[x]+=val;
		x += x & -x;
	}
}

int query(int x, int BIT[] ){
	int sum = 0;
	while(x>0)
	{
		sum+=BIT[x];
		x -= x & -x;
	}
	return sum;
}

int rangeQuery(int x,int y, int BIT[]){
	int sum =0 ;
	return query(y ,BIT) - query(x-1, BIT);
}


int main(){
	int n; cin>>n;
	int *BIT = new int[n+1] ;

	for(int i=1;i<=n;i++){
		int t; cin>>t;
		update(i, t ,n,BIT);
	}

	cout << rangeQuery(2,5, BIT);

	return 0;
}