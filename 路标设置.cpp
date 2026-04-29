#include<iostream>
using namespace std;
int main(){
	int L,N,K;
	cin>>L>>N>>K;
	int a[N];
	for(int i=0;i<N;i++)cin>>a[i];
    int l=1,r=L;
 while(l<r){
 	int mid=(l+r)/2;
 	int need=0;
 	for(int i=1;i<N;i++)
 	{
 		int d=a[i]-a[i-1];
 		need+=(d-1)/mid;
	 }
	 if(need<=K){
	 	r=mid;
	 }else{
	 	l=mid+1;
	 }
 	
 }
 cout<<l<<endl;
	return 0;
} 
