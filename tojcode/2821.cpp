#include<iostream>  //acmtju2821拿1356改的 
#include<cstring>
using namespace std;  
int n,w[20],sum,ans,l,r,i;  
bool dp[10000][20];
int main()  
{  
    while(cin>>n,n)
	{
		memset(dp,0,sizeof(dp));  
		 
		sum=0;  
		for(i=1;i<=n;i++)
			cin>>w[i],sum+=w[i];  
		dp[0][0]=1; 
		dp[0][19]=1;
		for(i=1;i<=n;++i) 	
        for(int j=sum;j>=w[i];--j) 
        if(dp[j-w[i]][19])  
        {  
	       dp[j][19]=1; 
	       
        }  
		ans=sum/2;
		while(!dp[ans][19])
			--ans;  
		cout<<sum-2*ans<<endl;  				
	}
	return 0;  
}  