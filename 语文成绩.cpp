#include<iostream>
using namespace std;
const int N=5000005;
int main(){
	long long n,p;
	cin>>n>>p;
	int a[N]={0},b[N]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]-a[i-1];
	}
	while(p--){
	long long l,r,m;
	cin>>l>>r>>m;
	b[l]+=m;
	b[r+1]-=m;
	}
	long long ans=1e18;
	for(int i=1;i<=n;i++){
		a[i]=b[i]+a[i-1];
		if(a[i]<=ans)ans=a[i];
	}
	cout<<ans;
	return 0;
}
