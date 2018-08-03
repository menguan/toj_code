#include<iostream>
#include<algorithm>
using namespace std;
int a[1500],dp[1500],cnt[1500];
int main(){
	int T,n,t,m;
	cin>>T;
	while(T--)
	{
		cin>>n>>t>>m;
		dp[0]=0; cnt[0]=0;
		for(int i=1;i<=m;i++)
			cin>>a[i];
		for(int i=1;i<=m;i++){
			dp[i]=2*t+max(dp[max(i-n,0)],a[i]);
			cnt[i]=cnt[max(i-n,0)]+1;
		}
		cout<<dp[m]-t<<" "<<cnt[m]<<endl;
	}
}
