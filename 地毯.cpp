#include<iostream>
using namespace std;
const int N=1005;
int main(){
	int n,m;
	cin>>n>>m;
	int a[N][N]={0},b[N][N]={0};
	while(m--){
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		b[x1][y1]+=1;
		b[x2+1][y1]-=1;
		b[x1][y2+1]-=1;
		b[x2+1][y2+1]+=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=b[i][j]+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
} 
