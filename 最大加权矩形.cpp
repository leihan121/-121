#include<iostream>
#include<algorithm>
using namespace std; 
const int N=130;
int a[N][N];
int n;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
		cin>>a[i][j];
	}
    }
	int ans=-1e9;
	for(int top=1;top<=n;top++){
		int sum[N]={0};
		for(int bottom=top;bottom<=n;bottom++){
			for(int j=1;j<=n;j++){
				sum[j]+=a[bottom][j];
			}
			int cur=0;
		    for(int j=1;j<=n;j++){
			cur=max(sum[j],cur+sum[j]);
			ans=max(ans,cur);
		}
		}	
	}
	cout<<ans<<endl;
	return 0;
}
