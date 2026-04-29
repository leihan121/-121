#include<iostream>
using namespace std;

const int N=100005;
int main(){
	int n;
	cin>>n;
	int a[N];
	int b[N]={0};
	for(int i=1;i<=n;i++){
	cin>>a[i];
	b[i]=b[i-1]+a[i];
	}
	int m;
	cin>>m;
	while(m--){
		int l,r;
		cin>>l>>r;
		cout<<b[r]-b[l-1]<<endl;
	}
	return 0;
} 
