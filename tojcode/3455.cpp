#include<iostream>  
#include<cstring>
using namespace std;  
int n,w[20],sum,ans,l,r,i;  
bool dp[10100];
int main()  
{  
    int t;
    cin>>t;
    while(t--)
	{
  int n=10;		
  memset(dp,0,sizeof(dp));  
		 
		sum=0;  
		for(i=1;i<=n;i++)
			cin>>w[i],sum+=w[i];  
		dp[0]=1; 
		dp[0]=1;
		for(i=1;i<=n;++i) 	
        for(int j=sum;j>=w[i];--j) 
        if(dp[j-w[i]])  
        {  
	       dp[j]=1; 
	       
        }  
		ans=sum/2;
		while(!dp[ans])
			--ans;  
		cout<<ans<<endl;  				
	}
	return 0;  
}  