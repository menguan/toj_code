#include<iostream>  
#include<cstring>
using namespace std;  
int n,w[103],sum,ans,l,r,i;  
bool dp[45010][110];
int main()  
{  
    while(cin>>n)
	{
		memset(dp, 0, sizeof(dp));  
		 
		sum=0;  
		for(i=1;i<=n;i++)
			cin>>w[i],sum+=w[i];  
		dp[0][0]=1; 
		dp[0][101]=1;
		for(i=1;i<=n;++i) 	
        for(int j=sum;j>=w[i];--j) 
        if(dp[j-w[i]][101])  
        {  
	       dp[j][101]=1; 
	       for(int k=0;k<n;k++)  
	       if(dp[j-w[i]][k])
           dp[j][k+1]=1;  
        }  
		ans=sum/2;
		while(!(dp[ans][101] && (dp[ans][n/2] || dp[ans][(n+1)/2])))			--ans;  
		cout<<ans<<" "<<sum-ans<<endl;  				
	}
	return 0;  
}  