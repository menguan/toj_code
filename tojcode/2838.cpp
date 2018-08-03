#include<iostream>
#include<cstring>
using namespace std;
bool dp[8000000]={0};
int ca[30];
int main()
{
  int c,n;
  cin>>c>>n;
  int sum=0;
  for(int i=0;i<n;i++)
  {
    cin>>ca[i];
    sum+=ca[i];
  }
  dp[0]=1;
        for(int i=0;i<n;i++) 	
        for(int j=sum;j>=ca[i];j--) 
        if(dp[j-ca[i]])  
        {  
	       dp[j]=1; 
	       
        } 
  for(int i=c;i>=0;i--)
  {
    if(dp[i])
    {
      cout<<i<<endl;
      break;
    }
  }
  //while(1);
}                 
    
  